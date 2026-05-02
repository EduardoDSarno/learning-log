cmd + shift + v

# Project Specification: Minimal Solana-Style Contract Execution Engine (Rust)

## Overview

This project aims to design and implement a **minimal, Solana-inspired smart contract execution engine** in Rust. The system will simulate core concepts of the :contentReference[oaicite:0]{index=0} programming model—accounts, programs, instructions, and signatures—without relying on the real Solana runtime or network.

The goal is **not** to recreate Solana, but to demonstrate a clear understanding of:
- How Solana-style contracts (programs) are invoked
- How accounts and state are validated and mutated
- How cryptographic guarantees are enforced
- How deterministic execution is achieved

This project is scoped to be completed in approximately **8 hours**.

---

## Project Goal

Deliver a **command-line Rust application** that can:

- Define and deploy immutable “programs” (contracts)
- Execute instructions against programs
- Validate caller authority via cryptographic signatures
- Enforce account ownership and mutability rules
- Deterministically update account state

The final result should clearly show how Solana’s execution model works at a conceptual and architectural level.

---

## Functional Requirements

### 1. Accounts Model

The system must implement an **account-based state model** inspired by Solana:

Each account must include:
- A public key (address)
- An owner (program ID)
- A balance (u64, representing lamports)
- Arbitrary data (byte array or structured data)
- Mutability flag (read-only vs writable)

Rules:
- Only the owning program may modify account data
- Balance updates must preserve total supply
- Read-only accounts must never be mutated

---

### 2. Programs (Contracts)

Programs are:
- Immutable once deployed
- Identified by a hash of their code
- Stateless by themselves (all state lives in accounts)

Programs must expose one or more **instruction handlers**, for example:
- `initialize`
- `transfer`
- `release`
- `close`

---

### 3. Instructions

An instruction represents a single program invocation and must include:
- Program ID
- List of accounts (with signer + writable flags)
- Instruction data (function selector + parameters)

Rules:
- Required signer accounts must provide valid signatures
- Programs may only modify accounts explicitly passed in
- Instruction execution must be deterministic

---

### 4. Cryptography & Authorization

The engine must:
- Verify transaction signatures using a standard Rust crypto crate
- Ensure that only authorized signers can invoke restricted instructions
- Reject any instruction with invalid or missing signatures

Replay protection can be minimal (e.g., nonce or recent block hash simulation).

---

### 5. Execution Engine

The runtime must:
- Dispatch instructions to the correct program
- Enforce Solana-style constraints before execution
- Apply state changes atomically (all-or-nothing)
- Fail gracefully with explicit error types

---

### 6. Command-Line Interface (CLI)

The CLI must support at least:

```bash
deploy <program_file>
c
