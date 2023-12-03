CC=gcc
CFLAGS=-O2

atct: atct.o game.h 	
	$(CC) -o atct atct.o $(CFLAGS)

clean:
	rm -f atct atct.o
