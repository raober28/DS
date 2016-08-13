#include "ds.h"

void deleteNode_by_key(struct node **head ,int n) {
	
	/*the list is empty*/
	if(*head == NULL) {
		printf("error: underflow: cannot delete from empty list\n");
		return;
	}

	struct node * prev_node = NULL;
	struct node * curr_node = *head;

	/*first node is the one to be deleted*/
	if(curr_node != NULL && curr_node->data == n)
	{
		*head = curr_node->next;
		free(curr_node);
		return;
	}


	while(curr_node != NULL)
	{
		if(curr_node->data == n)
			break;

		prev_node = curr_node;
		curr_node = curr_node->next;
	}

	if(curr_node == NULL)
	{
		printf("error: cannot find element to  be deleted\n");
		return;
	}

	prev_node->next = curr_node->next;

	free(curr_node);
}

