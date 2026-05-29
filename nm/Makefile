CC=gcc
BIN=process.exe
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

$(BIN):$(OBJ)
	$(CC) -o $(BIN) $(OBJ)

%.o:%.c
	$(CC) -c $(SRC)

.PHONY:clean
clean:
	rm -f $(BIN) $(OBJ)
