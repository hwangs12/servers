CC = gcc

ifeq ($(shell uname -s), Darwin)
	LIBS = -pthread
else
	LIBS = -lpthread
endif

CFLAGS = -Wall -g

SRC=$(wildcard *.c)
OBJS = $(SRC:.c=.o)

TARGET = main.out

$(TARGET): $(OBJS)
	gcc -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(LIBS) -c $< -o $@
