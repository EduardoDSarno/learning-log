CC      = gcc
CFLAGS  = -Wall -Wextra

SRCS    = main.c sync.c helpers/checksum.c helpers/pseIPHeader.c
OBJS    = $(SRCS:.c=.o)
TARGET  = tcp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

main.o: main.c header.h helpers/helpers.h helpers/pseIPHeader.h
sync.o: sync.c header.h helpers/helpers.h helpers/pseIPHeader.h
helpers/checksum.o: helpers/checksum.c helpers/helpers.h helpers/pseIPHeader.h
helpers/pseIPHeader.o: helpers/pseIPHeader.c helpers/pseIPHeader.h

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	sudo ./$(TARGET)

.PHONY: all clean run
