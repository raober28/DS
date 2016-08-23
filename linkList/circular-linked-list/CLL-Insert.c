#include "cll.h"


void insert_sorted(struct node **tail, int n)
{
	struct node *new = new_node(n), *temp, *head;

	/*insert node at empty list*/
	if(*tail == NULL)
	{
		*tail = new;
		(*tail)->next = *tail;
		return;
	}

	head = (*tail)->next;
	temp = head;

	/*insert node at front*/
	if(n < head->data)
	{
		new->next = head;
		(*tail)->next = new;	
		return;
	}

	/*insert at last node*/
	if(n > (*tail)->data)
	{
		new->next = (*tail)->next;
		(*tail)->next = new;
		*tail = new;
		return;
	}

	/*iterate through the loop and find the location after which to insert*/
	while(temp->next->data < n)
		temp = temp->next;


	new->next = temp->next;
	temp->next = new;


}