CC = gcc
CFLAGS = -c
OBJ = ./src/int_array.o
BIN = main.out
MAIN_SRC = ./src/main.c
INT_ARRAY_SRC = ./src/int_array.c

# default target
all: $(BIN)

# build int_array.o
$(OBJ): $(INT_ARRAY_SRC)
	$(CC) $(CFLAGS) $< -o $@

# build main executable
$(BIN): $(OBJ) $(MAIN_SRC)
	$(CC) $^ -o $@

# clean up
clean:
	rm -f $(OBJ) $(BIN)
