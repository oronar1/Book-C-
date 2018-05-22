OBJS = bookmain.o booklist.o book.o
MODEL = s
CC=gcc
CFLAGS= -c -g -Wall

all:project

project:bookmain.o booklist.o book.o
	$(CC) bookmain.o booklist.o book.o -o project

bookmain.o : bookmain.c
	$(CC) $(CFLAGS)   bookmain.c -c

booklist.o : booklist.h booklist.c
	$(CC) $(CFLAGS)  booklist.h booklist.c -c

book.o : book.h book.c
	$(CC) $(CFLAGS) book.h  book.c -c 

clean:  rm -rf bookmain.o
	rm -rf book.o
	rm -rf booklist.o
	strip -s res
	
