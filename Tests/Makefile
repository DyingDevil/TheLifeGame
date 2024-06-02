CC=gcc
MODULES_DIR = ../bin/modules/
EXECS_DIR = ../bin/exe/
TSTS_DIR = ../bin/tests/
PLUGS_DIR = ../bin/tests/plugs/
CFLAGS = -static -O0
MODULES = UI logic error core save settings
TESTING_MODULES = $(addsuffix .o, $(addprefix Test, UI logic error save settings))
DIRECTORIES_FLAGS = $(addsuffix /tests/, $(addprefix -I../src/,$(MODULES)))
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
LIBS = $(addprefix -l, $(MODULES))
all: UI logic error save settings core main
UI:
	$(MAKE) -C ../src/UI/tests/
logic:
	$(MAKE) -C ../src/logic/tests/
error:
	$(MAKE) -C ../src/error/tests/
save:
	$(MAKE) -C ../src/save/tests/
settings:
	$(MAKE) -C ../src/settings/tests/
core:
	$(MAKE) -C ../src/core/tests/
main:
	$(CC) $(CFLAGS) $(DIRECTORIES_FLAGS) -c $(SRC) -o $(TSTS_DIR)$(OBJ)
	$(CC) $(CFLAGS) -L$(MODULES_DIR) -o $(EXECS_DIR)CoreTest.exe $(TSTS_DIR)Testcore.o $(wildcard $(PLUGS_DIR)*.o) -lcore
	$(CC) $(CFLAGS) -L$(MODULES_DIR) -o $(EXECS_DIR)AllTests.exe $(TSTS_DIR)$(OBJ) $(addprefix $(TSTS_DIR),$(TESTING_MODULES)) $(LIBS)
.PHONY: clean
clean:
	del ..\bin\tests\ /Q /S