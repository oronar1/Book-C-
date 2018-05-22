/* file: main.c */
#include <stdio.h>
#include <stdlib.h>

#include "booklist.h"  /* for using the book list types and fuctions */
#include "book.h"		/* for using the book types and fuctions */

/* display menu to the user */
void menu()
{
	printf("\n\n\n\n\n");
	puts("Book program main menu");
	puts("------------------------");
	puts("a. Add a book to the list");
	puts("d. Delete a book from the list");
	puts("i. Find a book by ID");
	puts("n. Find a book by name");
	puts("p. Print all books");
	puts("x. Exit");
	puts("\n\n\n\n\n\n\n\n");
}

/* pause - wait for user confirmation */
void pause()
{
	puts("\nHit Enter to continue");
	getchar();
}

int main()
{
	int  c;
	int  num;
	List  list;
	BookPtr pbook;
	String name, temp;


	list_init(&list);

	for(;;)  /* forever */
	{
		/* display menu */
		menu();

		c = getchar(); 
		gets(temp); /* read up to the newline character */
		switch(c)
		{
		case 'a': /* add Book */
			pbook = malloc(sizeof(Book));
			book_input(pbook);
			list_add_book(&list, pbook);
			pause();
			break;
		case 'd': /* delete Book */
			printf("Enter an ID of book to delete: ");
			if(scanf("%d", &num) == 1)  /* successful read */
				list_del_book(&list, num);
			pause();
			break;
		case 'i': /* find a book by ID */
			printf("Enter a Book ID:");
			scanf("%d",&num);
			pbook = list_find_by_ID(&list, num);
			if(pbook)
				book_output(pbook);
			pause();
			break;
		case 'n': /* find a book by name */
			printf("Enter a Book name:");
			gets(name);
			pbook = list_find_by_name(&list, name);
			if(pbook)
				book_output(pbook);
			pause();
			break;
		case 'p': /* print the book list */
			list_print(&list);
			pause();
			break;
		case 'x': /* Exit */
			list_clear(&list); /* free and clear the list data */
			return 0;
		default:
			break;
		}
	}
	return 0;
}
