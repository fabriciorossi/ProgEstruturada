CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Wvla -g

SRCS = bignumber.c client.c
OBJS = $(SRCS:.c=.o)
TARGET = executavel

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)
