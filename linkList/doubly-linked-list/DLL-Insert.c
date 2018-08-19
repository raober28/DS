#include "dll.h"

/*push: insert a node at the begining of the linkde list*/
void push(struct node **head_ref, int n)
{
	//allocate node in memory
	struct node *new = new_node(n);

	if(*head_ref == NULL)
	{
		*head_ref = new;
		return;
	}

	new->prev = NULL;
	new->next = *head_ref;
	(*head_ref)->prev = new;
	(*head_ref) = new;

}


/*insert_after: insert node after the given node*/
void insert_after(struct node **prev_node, int n)
{
	struct node *new = new_node(n), *next_node = (*prev_node)->next;

	/*list is empty*/
	if(*prev_node == NULL) 
	{
		*prev_node = new;
		return;
	}

	/*inserting afterr last node*/
	if(next_node == NULL) 
	{
		(*prev_node)->next = new;
		new->prev = *prev_node;
		return;
	}


	(*prev_node)->next = new;
	new->prev = *prev_node;
	
	new->next = next_node;
	next_node->prev = new;
}


/*insert_before: insert a node before the given node*/
void insert_before(struct node **next_node, int n)
{

	struct node *new = new_node(n), *prev_node = (*next_node)->prev;

	/*list is empty*/
	if(*next_node == NULL)
	{		
		printf("error: next node cannot be NULL");
		return;
	}

	/*insert before first node*/
	if(prev_node == NULL)
	{	
		push(next_node, n);
		return;
	} 

	(*next_node)->prev = new;
	new->next = *next_node;
	
	prev_node->next = new;
	new->prev = prev_node;

}


/*append: insert node at the end of linked list*/
void append(struct node **head_ref, int n)
{
	struct node *new = new_node(n), *curr_node, *prev_node;

	/*appending in an empty list*/
	if(*head_ref == NULL)
	{
		*head_ref = new;
		return;
	}

	curr_node = *head_ref;

	while(curr_node != NULL)
	{
		prev_node = curr_node;
		curr_node = curr_node->next;
	}
	

	prev_node->next = new;
	new->prev = prev_node;
}