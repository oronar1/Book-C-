/* file: booklist.h */
#ifndef BOOKLIST_H
#define BOOKLIST_H
#include "book.h"

/**************** TYPES *******************************/
typedef enum {FALSE=0, TRUE=1} Boolean;

/* list node */
typedef struct ListNode_tag
{
	BookPtr		pbook;
	struct		ListNode_tag  *next;
} ListNode;


/* list structure */
typedef struct 
{
	ListNode	*head;		/* head of the book list */
	ListNode	first;		/* first dummy element */
	int			count;
} List;

/************** FUNCTION PROTOTYPES *******************/
void	list_init(List *plist);
void	list_clear(List *plist);
void	list_add_book(List *plist, BookPtr pbook);
void	list_del_book(List *plist, int num);
void	list_print(List *plist);
BookPtr	list_find_by_name(List *plist, char name[]);
BookPtr	list_find_by_ID(List *plist, int ID);
Boolean	list_exist(List *plist, int num);

#endif
