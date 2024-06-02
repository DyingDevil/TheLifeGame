CC = gcc
TESTED_DIR = ../
BUILD_DIR = ../../bin/tests
HEADERS = -I../../UI -I../../settings -I../../save -I../../logic -I../../error
PLUGS_DIR = ../../../bin/tests/plugs/
CFLAGS = -static -O0 -I$(TESTED_DIR) $(HEADERS)
main:
	$(CC) $(CFLAGS) -c -o $(PLUGS_DIR)UI.o UI.c
	$(CC) $(CFLAGS) -c -o $(PLUGS_DIR)settings.o settings.c
	$(CC) $(CFLAGS) -c -o $(PLUGS_DIR)save.o save.c
	$(CC) $(CFLAGS) -c -o $(PLUGS_DIR)logic.o logic.c
	$(CC) $(CFLAGS) -c -o $(PLUGS_DIR)error.o error.c
	$(CC) $(CFLAGS) -c -o ../../../bin/tests/Testcore.o Testcore.c