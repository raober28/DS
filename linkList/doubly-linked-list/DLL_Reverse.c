#include "dll.h"

void reverse(struct node **head_ref)
{
	if(*head_ref == NULL)
	{
		printf("Underflow: cannot reverse empty list\n");
		return;
	}

	if( (*head_ref)->next == NULL)
	{
		printf("warning: cannot reverse list with one node\n");
		return;
	}


	struct node *curr_node, *temp, *next_node, *prev_node;


	curr_node = temp = *head_ref;
	next_node = curr_node->next;



	temp->prev = next_node;
	
	curr_node = curr_node->next;

	while(curr_node->next != NULL)
	{
		temp = curr_node;
		prev_node = temp->prev;
		next_node = temp->next;

		curr_node = curr_node->next;

		temp->prev = next_node;
		temp->next = prev_node;

	}

	curr_node->next = temp;
	
	(*head_ref)->next = NULL;
	*head_ref =  curr_node;
}





