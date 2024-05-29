CC=gcc
TESTING_OBJ_DIR = ../
BUILD_DIR = ../../../bin/tests/
CFLAGS = -static -O0 -I$(TESTING_OBJ_DIR)
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -o $(BUILD_DIR)$(OBJ)