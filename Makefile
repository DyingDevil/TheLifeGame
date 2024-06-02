CC=gcc
CFLAGS = -static -O0
TARGET = TheLifeGame.exe
MODULES_DIR = ./bin/modules/
EXECS_DIR = ./bin/exe/
FLAGS_HEADER_DIRS = $(addsuffix /,$(addprefix -I./src/,UI logic core error save settings))
LIBS = $(addprefix -l,UI logic core error save settings)
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
.PHONY: test
test:
	$(MAKE) -C ./Tests/
	.\bin\exe\AllTest.exe
main:
	$(CC) $(CFLAGS) $(FLAGS_HEADER_DIRS) -c -o ./bin/main.o main.c
	$(CC) $(CFLAGS) -Lbin/modules/ ./bin/main.o -obin/exe/$(TARGET) $(LIBS)
.PHONY: clean
clean:
	del .\bin\ /Q /S
	