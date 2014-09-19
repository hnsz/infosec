CC=cc
FLAGS= -Wall --std=c99 -pedantic
CFLAGS= $(FLAGS) -c


main: main.c strxor.o
	$(CC) $(FLAGS) main.c

strxor: strxor.c strxor.h
	$(CC) $(CFLAGS) strxor.c
