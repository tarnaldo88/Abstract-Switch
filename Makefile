CC=gcc
CFLAGS=-Iinclude -Wall -Wextra -g

SRCS=src/main.c src/switch.c src/backend.c
OBJS=$(SRCS:.c=.o)

all: switch

switch: $(OBJS)
	$(CC) $(OBJS) -o switch

clean:
	rm -f $(OBJS) switch