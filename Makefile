CC=gcc
CFLAGS=-Wall -Wextra -std=c99 -pedantic -ggdb -fsanitize=address -o
OUT=elfie
DOUT=elfie_debug

install:
	mkdir build
	$(CC) -c src/elfie.c $(CFLAGS) ./build/elfie.o
	$(CC) -c src/cases.c $(CFLAGS) ./build/cases.o
	$(CC) -c src/main.c $(CFLAGS) ./build/main.o
	$(CC) ./build/*.o $(CFLAGS) $(OUT)
	rm -rf ./build/
