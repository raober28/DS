#include"dll.h"

void delete(struct node **curr_node)
{

	struct node *temp;
	if(*curr_node == NULL)
	{
		printf("error: cannot delete empty node\n");
		return;
	}
	/*node to be deleted is the first node*/
	if((*curr_node)->prev == NULL)
	{
		temp = *curr_node;
		*curr_node = (*curr_node)->next;
		free(temp);
		return;
	}

	/*node to be deleted is the last node*/
	if((*curr_node)->next == NULL)
	{	
		temp = *curr_node;
		(*curr_node) = (*curr_node)->prev;
		(*curr_node)->next = NULL;
		free(temp);
		return;
	}


	struct node *prev = (*curr_node)->prev, *next = (*curr_node)->next;

	temp = *curr_node;
	prev->next = next;
	next->prev = prev;

	free(temp);

}