#include"ds.h"


void reverse(struct node **head_ref)
{
	struct node *curr_node, *prev_node, *next_node, *temp;

	curr_node = *head_ref;

	/*empty list*/
	if(curr_node == NULL)
		return;

	/*list with only one node*/
	if(curr_node->next == NULL)
		return;


	temp = curr_node;
	
	prev_node = curr_node;
	curr_node = curr_node->next;

	temp->next = NULL;	//making first node last


	while(curr_node != NULL)
	{
		temp = curr_node;
		curr_node = curr_node->next;



		temp->next = prev_node;		//making previous node next to the current node 
		prev_node = temp;
	}


	*head_ref = temp;
}