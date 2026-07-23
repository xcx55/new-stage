
CC=g++
CFLAGS=-g -O0 -std=c++11 -Wall
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
BIN=exe

$(BIN): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(BIN) $(OBJ)
