CC = gcc

all: heap.o sample.o
	$(CC) heap.o sample.o -o heap

heap.o: heap.c heap.h
	$(CC) heap.c -c -o heap.o

sample.o: sample.c heap.h
	$(CC) sample.c -c -o sample.o

clean:
	@rm -f *.o heap