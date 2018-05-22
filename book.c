/* file: book.c - An implementation file for the Book */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "book.h"

/************** FUNCTION BODIES ************************/

/* print one book data to the standard output */
void book_output(BookPtr pbook)
{
	printf("book %s:\n",pbook->name);
	printf("\twriter=%s\n",pbook->writer);
	printf("\tpublisher=%s\n",pbook->publisher);
	printf("\tyear=%d\n",pbook->year);
	printf("\tcost=%.2f\n",pbook->cost);
	printf("\tID=%d\n",pbook->ID);
}

/* read and initialize book data from the standard input */
void book_input(BookPtr pbook)
{
	String temp;

	puts("Enter book name, writer, and publisher separated by newlines:");
	gets(temp);
	pbook->name = strdup(temp);
	gets(temp);
	pbook->writer = strdup(temp);
	gets(temp);
	pbook->publisher  = strdup(temp);

	printf("Enter publishing year:");	
	scanf("%d", &pbook->year);
	printf("Enter cost:");	
	scanf("%f", &pbook->cost);
	printf("Enter ID:");	
	scanf("%d", &pbook->ID);
	gets(temp); /* to read up to the end of line */
}

/* free the book allocated memory */
void book_clear(BookPtr pbook)
{
	free(pbook->name);
	free(pbook->writer);
	free(pbook->publisher);
	free(pbook);
}

