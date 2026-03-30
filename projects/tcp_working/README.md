# TCP 3-Way Handshake — Manual Implementation

This project manually implements the TCP 3-way handshake using raw sockets (sending)
and libpcap (receiving), without relying on the OS TCP stack.

---

## How the 3-Way Handshake Works

```
CLIENT                          SERVER
  |                               |
  |------- SYN (seq=X) --------->|   Step 1: client initiates
  |                               |
  |<----- SYN-ACK (seq=Y,        |   Step 2: server acknowledges
  |         ack=X+1) ------------|             and sends its own seq
  |                               |
  |------- ACK (ack=Y+1) ------->|   Step 3: client acknowledges
  |                               |
  |           CONNECTED           |
```

- **SYN**: "I want to connect, my sequence starts at X"
- **SYN-ACK**: "OK, I acknowledge X (ack=X+1), my sequence starts at Y"
- **ACK**: "I acknowledge Y (ack=Y+1), we are connected"

---

## Project Structure

```
main.c                  — entry point, spawns server and client threads
makefile                — build system (gcc, -lpthread, -lpcap)
client/
  client.h              — declarations
  client.c              — steps 1 and 3 (send SYN, receive SYN-ACK, send ACK)
server/
  server.h              — declarations
  server.c              — steps 2 and 4 (receive SYN, send SYN-ACK, receive ACK)
shared/
  helpers.h             — shared types, constants, and function declarations
  addr_init.c           — socket address setup, connection_init, get_local_ip
  send_packet.c         — raw socket packet sender (used by both client and server)
  listen_packet.c       — pcap-based packet receiver (used by both client and server)
  checksum.c            — TCP checksum calculation
  pseIPHeader.h/.c      — pseudo IP header (needed for TCP checksum)
```

---

## Data Flow

### main.c
Creates a `ConnectionData` struct holding two `sockaddr_in` structs:
- `source`      = client address (port 12345)
- `destination` = server address (port 80)

Both use the machine's real non-loopback IP (discovered via `get_local_ip()`).
Both threads share this same struct — it is read-only after creation.

### Thread startup order
```
main() ─── pthread_create(server_thread)
        └─ sleep(1 second)              ← gives server time to open pcap
        └─ pthread_create(client_thread)
```

### server_thread (server/server.c)
```
1. listen_packet(TH_SYN,        port=80)   ← blocks until SYN arrives
2. usleep(150ms)                            ← gives client time to open pcap
3. send_packet(src=port80, dst=port12345,
               flags=SYN|ACK)
4. listen_packet(TH_ACK,        port=80)   ← blocks until ACK arrives
5. print "CONNECTED"
```

### client_thread (client/client.c)
```
1. send_packet(src=port12345, dst=port80,
               flags=SYN,  seq=random)
2. listen_packet(TH_SYN|TH_ACK, port=12345) ← blocks until SYN-ACK arrives
3. send_packet(src=port12345, dst=port80,
               flags=ACK,  ack=server_seq+1)
```

---

## Key Implementation Details

### Why raw sockets for sending?
`socket(PF_INET, SOCK_RAW, IPPROTO_TCP)` lets us build the TCP header manually
and send it directly, bypassing the OS TCP stack. This is how we control every
field (flags, seq number, ack number, checksum) ourselves.

### Why pcap for receiving?
On macOS, raw sockets do NOT receive packets that travel over `lo0` (loopback).
macOS routes all same-host traffic through loopback regardless of IP address,
and raw socket copies are not delivered there.

libpcap hooks in via BPF (Berkeley Packet Filter) at a lower layer and CAN
receive loopback packets. It is pre-installed on macOS — no extra install needed.

### Why get_local_ip() instead of 127.0.0.1?
Even with pcap, we use the machine's real IP (en0) so both the sender and
receiver agree on addresses for checksum calculation. 127.0.0.1 would also work
with pcap but the real IP makes the packets look more realistic in Wireshark.

### TCP Checksum (shared/checksum.c)
The checksum is computed over a "pseudo IP header" + TCP header (RFC 793):
```
Pseudo header layout (12 bytes):
  [src IP 4B][dst IP 4B][zero 1B][protocol 1B][TCP length 2B]
```
The pseudo header is not transmitted — it only exists to include IP-level
information in the checksum, protecting against misrouted packets.

### Sequence and Acknowledgment numbers
- All seq/ack values are stored in **network byte order** (big-endian) in the header.
- Before doing arithmetic on them, convert with `ntohl()`.
- After doing arithmetic, convert back with `htonl()`.
- Example: ack = ntohl(their_seq) + 1, then store htonl(ack).

---

## Wireshark RST Lines (Red/Black) — Why They Appear

When your raw SYN arrives at port 80, the macOS kernel sees it. Since no normal
socket is bound to port 80, the kernel automatically sends a RST. This happens
for every packet in the handshake (SYN, SYN-ACK, ACK).

These RSTs are harmless to your implementation — pcap captures the real handshake
packets before the kernel reacts. They are a side-effect of running a manual TCP
stack alongside the OS TCP stack, which has no knowledge of your raw connections.

---

## Bugs Fixed vs mytcp (Your Debugging Guide)

Use this section to find and fix the same bugs in `mytcp/` yourself.

---

### Bug 1 — Flag Check Logic (listen_packet.c)

**Symptom**: the client accepts the wrong packet when waiting for SYN-ACK.

**Where to look**: the `while` loop condition in `listen_packet`.

**What is wrong**: the condition uses `!(flags & expected_flags)`. The `&` operator
checks if ANY bit in `expected_flags` is set in `flags`. When waiting for
`TH_SYN | TH_ACK` (both bits), a plain SYN packet has the SYN bit set, so
`SYN & (SYN|ACK) = SYN ≠ 0`, which makes `!(...)` false — the loop exits
thinking it found a SYN-ACK when it only got a SYN.

**How to fix**: change the condition so that ALL expected bits must be present.
Think about what operator/comparison would enforce "all bits set" rather than
"at least one bit set".

---

### Bug 2 — No Port Filtering (listen_packet.c)

**Symptom**: the server receives the wrong packet, or hits the retry limit and
returns NULL even when the right packet was sent.

**Where to look**: the loop inside `listen_packet`. Look at what it checks
before deciding a packet is relevant.

**What is wrong**: the raw socket (original code) receives ALL TCP traffic on
the machine. On a dev machine there is constant background TCP activity
(browsers, system services). With only 100 retries and no port check, the
function can exhaust retries on irrelevant traffic before the real packet arrives.

**How to fix**: before checking the flags, add a check that the packet's
destination port (`th_dport`, network byte order) matches the port you are
expecting. You will need to pass the expected destination port as a parameter.

---

### Bug 3 — Returning a Pointer into the Middle of a malloc'd Block (listen_packet.c)

**Symptom**: crash or memory corruption that appears randomly after the handshake,
or when valgrind is run.

**Where to look**: what `listen_packet` returns, and how the callers `free()` it.

**What is wrong**: `buffer` is allocated with `malloc(MAX_BUFFER_SIZE)`. The IP
header is at `buffer[0]`. The TCP header starts at `buffer + ip_hl*4`. The
function returns `received_header` which is that offset pointer — NOT the start
of the malloc'd block. When the caller does `free(received_syn)`, it is calling
`free` on a pointer that is N bytes past the start of the allocation. That is
undefined behavior and can silently corrupt the heap.

**How to fix**: before returning, allocate a fresh `struct tcphdr` with `malloc`,
`memcpy` the TCP header data into it, `free` the original buffer, and return the
new pointer. The caller can then safely `free` what it receives.

---

### Bug 4 — Socket File Descriptor Leaks (send_packet.c and listen_packet.c)

**Symptom**: after many calls the process runs out of file descriptors.
Observable with `lsof -p <pid> | grep -c socket`.

**Where to look**: every function that calls `socket(...)`.

**What is wrong**: both `send_packet` and `listen_packet` create a socket at the
top of the function but never call `close(sockfd)` before returning. Each call
leaks one file descriptor.

**How to fix**: add `close(sockfd)` on every exit path (normal return and any
early error returns).

---

### Bug 5 — PseudoIpHeader Field Width (shared/pseIPHeader.h)

**Symptom**: incorrect TCP checksum, though on macOS the OS may recalculate it
anyway so this might not cause visible failures.

**Where to look**: the `PseudoIpHeader` struct definition and compare it against
RFC 793 Section 3.1.

**What is wrong**: `tcp_segment_lenght` is declared as `uint8_t` (1 byte). The
RFC 793 pseudo-header defines this field as 16 bits (2 bytes). With `uint8_t`,
any TCP segment longer than 255 bytes would be silently truncated. The struct
is also the wrong size (11 bytes instead of 12), so the byte at offset 11 in
the checksum calculation is padding garbage.

Additionally, this value must be stored in network byte order (big-endian) since
it is included in a checksum calculation that the remote peer must reproduce.

**How to fix**: change the field to `uint16_t`, and in `pseIPHeader.c` wrap the
assignment in `htons()`.

---

### Bonus — Wrong Source/Destination in SYN-ACK (server/server.c)

**Symptom**: the server successfully receives SYN, but the client never receives
SYN-ACK. In debug output the SYN-ACK shows `sport=12345 dport=80` instead of
`sport=80 dport=12345`.

**Where to look**: the `send_ack_packet` call inside `server_thread`.

**What is wrong**: `ConnectionData` stores `source` = client (port 12345) and
`destination` = server (port 80). The server's SYN-ACK must go FROM port 80 TO
port 12345 — but the call passes `(data->source, data->destination)` which is
the opposite direction.

**How to fix**: swap the arguments so the server sends FROM its own port TO the
client port.

---

## Building and Running

```bash
make
sudo ./tcp
```

Requires `sudo` because raw sockets and pcap need elevated privileges.
