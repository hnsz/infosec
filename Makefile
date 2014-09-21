CC=cc
FLAGS=-Wall --std=c99 -pedantic
CFLAGS=$(FLAGS) -c
OBJS=feistel.o xcryptor.o


a.out: main.c $(OBJS)
	$(CC) $(FLAGS) main.c $(OBJS) -lcrypto

feistel.o: feistel.c feistel.h 
	$(CC) $(CFLAGS) feistel.c

xcryptor.o: xcryptor.c xcryptor.h
	$(CC) $(CFLAGS) xcryptor.c


clean: *.o
	rm *.o
