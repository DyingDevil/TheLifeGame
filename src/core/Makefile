CC = gcc
TARGET = core.a
BUILD_DIR = ../../bin/modules
CFLAGS = -I../UI -I../settings -I../save -I../logic -I../error
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
TARGET_LIB = lib$(TARGET)
$(OBJ):$(SRC)
	$(CC) $(CFLAGS) -c $< -o $(BUILD_DIR)$@
	ar rcs $(BUILD_DIR)$(TARGET_LIB) $(BUILD_DIR)$(OBJ)