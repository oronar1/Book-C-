/* file: booklist.c - An implementation file for the book list */
#include <stdio.h>
#include <string.h>  /* for strcmp() */
#include <stdlib.h>
#include "booklist.h"
#include "book.h"

/************** FUNCTION BODIES ************************/
/* initialize the book list */
void list_init(List *plist)
{
	plist->first.next = NULL;
	plist->head = &plist->first;
	plist->count = 0;
}

/* clear and free the list nodes */
void list_clear(List *plist){
	ListNode *p, *q;
	/* go through list elements with pointers p and q and free elements */
	p=plist->head->next;
	while(p != NULL)	{
		q = p->next;  /* save pointer to next element */
		book_clear(p->pbook); /* free allocated memory in the book struct */
		free(p); /* free the list node */
		p = q;
	}
	list_init(plist);
}

/* add a new book to the list */
void list_add_book(List *plist, BookPtr pbook){
	ListNode *new_node, *p;
	new_node = malloc(sizeof(ListNode));
	new_node->pbook = pbook;
	for(p=plist->head; p->next!=NULL ; p=p->next)
		if(new_node->pbook->ID < p->next->pbook->ID)
			break;
	/* at this point p->next is the place to insert */
	new_node->next = p->next;
	p->next = new_node;
	plist->count++;
}

/* delete a book from the list */
void list_del_book(List *plist, int num){
	ListNode *p, *temp;
	for(p=plist->head; p->next!=NULL ; p=p->next)	{
		if(p->next->pbook->ID == num)	{
			temp = p->next;
			p->next = p->next->next;
			book_clear(temp->pbook); /* clear and free the book allocated memory */
			free(temp); /* free the list node */
			plist->count--;
			return;
		}
	}

	/* didn't find the record - print an error message */
	puts("Error: Record does not exist!");
	return;
}

/* output book list  */
void list_print(List *plist){
	ListNode *p;

	printf("\n\nBooks:\n");
	for (p=plist->head->next; p!=NULL; p=p->next)
		book_output(p->pbook);
}

/* find a book by it's name */
BookPtr list_find_by_name(List *plist, char name[])
{
	ListNode *p;
	for(p=plist->head->next; p!=NULL ; p=p->next)
		if(strcmp(p->pbook->name, name)==0)
			return p->pbook;
	return NULL;  /* not found */
}

/* find a book by it's ID */
BookPtr list_find_by_ID(List *plist, int ID)
{
	ListNode *p;

	for(p=plist->head->next; p!=NULL ; p=p->next)
		if(p->pbook->ID == ID)
			return p->pbook;
	return NULL;  /* not found */
}

/* is a given serial number exist in the list */
Boolean list_exist(List *plist, int num)
{
	ListNode *p;

	for(p=plist->head->next; p!=NULL ; p=p->next)
		if(p->pbook->ID == num)
			return 1; /* exist */
	return 0;	/* does not exist */
}

