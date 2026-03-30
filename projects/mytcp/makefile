CC      = gcc
CFLAGS  = -Wall -Wextra

SRCS    = main.c \
          client/client.c \
          server/server.c \
          shared/send_packet.c \
          shared/listen_packet.c \
          shared/checksum.c \
          shared/addr_init.c \
          shared/pseIPHeader.c
OBJS    = $(SRCS:.c=.o)
TARGET  = tcp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) -lpthread

main.o: main.c client/client.h server/server.h shared/helpers.h shared/pseIPHeader.h
client/client.o: client/client.c client/client.h shared/helpers.h shared/pseIPHeader.h
server/server.o: server/server.c server/server.h shared/helpers.h shared/pseIPHeader.h
shared/send_packet.o: shared/send_packet.c shared/helpers.h shared/pseIPHeader.h
shared/listen_packet.o: shared/listen_packet.c shared/helpers.h shared/pseIPHeader.h
shared/checksum.o: shared/checksum.c shared/helpers.h shared/pseIPHeader.h
shared/addr_init.o: shared/addr_init.c shared/helpers.h
shared/pseIPHeader.o: shared/pseIPHeader.c shared/pseIPHeader.h

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	sudo ./$(TARGET)

.PHONY: all clean run
