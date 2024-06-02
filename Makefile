CC=gcc
CFLAGS = -static -O0
TARGET = TheLifeGame.exe
MODULES_DIR = ./bin/modules/
EXECS_DIR = ./bin/exe/
FLAGS_HEADER_DIRS = $(addsuffix /,$(addprefix -I./src/,UI logic error save settings core))
LIBS = -lcore -lUI -llogic -lerror -lsave -lsettings
all : UI logic core error save settings test main
UI:
	$(MAKE) -C ./src/UI/
logic:
	$(MAKE) -C ./src/logic/
error:
	$(MAKE) -C ./src/error/
core:
	$(MAKE) -C ./src/core/
save:
	$(MAKE) -C ./src/save/
settings:
	$(MAKE) -C ./src/settings/
test:
	$(MAKE) -C ./Tests/
	./bin/exe/CoreTest.exe
	./bin/exe/AllTests.exe
main:
	$(CC) $(CFLAGS) $(FLAGS_HEADER_DIRS) -c -o ./bin/main.o main.c
	$(CC) $(CFLAGS) -L$(MODULES_DIR) ./bin/main.o -obin/exe/$(TARGET) $(LIBS)
.PHONY: clean
clean:
	del .\bin\ /Q /S
	