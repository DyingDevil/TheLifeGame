CC=gcc
MODULES_DIR = ../bin/modules/
EXECS_DIR = ../bin/exe/
TSTS_DIR = ../bin/Tests/
PLUGS_DIR = ../bin/tests/plugs/
CFLAGS = -static -O0
MODULES = UI logic error core save settings
TESTING_MODULES = $(addsuffix .o, $(addprefix Test, UI logic error core save settings))
DIRECTORIES_FLAGS = $(addsuffix /tests/, $(addprefix -I../src/,$(MODULES)))
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
LIBS = $(addprefix -l, $(MODULES))
all: UI logic error core save settings main
UserIO:
	$(MAKE) -C ../src/UI/tests/
RobotIO:
	$(MAKE) -C ../src/logic/tests/
Storage:
	$(MAKE) -C ../src/error/tests/
ErrorHandler:
	$(MAKE) -C ../src/core/tests/
GameSystem:
	$(MAKE) -C ../src/save/tests/
Controller:
	$(MAKE) -C ../src/settings/tests/
main:
	$(CC) $(CFLAGS) $(DIRECTORIES_FLAGS) -c $(SRC) -o $(TSTS_DIR)$(OBJ)
	$(CC) $(CFLAGS) -L$(MODULES_DIR) -o $(EXECS_DIR)AllTests.exe $(TSTS_DIR)$(OBJ) $(addprefix $(TSTS_DIR),$(TESTING_MODULES)) $(LIBS)
.PHONY: clean
clean:
	del ..\bin\tests\ /Q /S