#include "ds.h"

/*rotate_LinkedList: rotates a linked list counter-clockwise and 
updates the head. */
struct node *rotate_LinkedList(struct node *head, int k)
{

	struct node *curr_node, *prev_node, *new_last_node, *new_head;


	curr_node =  head;

	if(head	 == NULL || k == 0)
		return NULL;


	int length = length_of_list(head);
	
	/*if k is greater than length of list rotate it by its length*/
	if(k > length)
		k = length;

	if(k == length)
	{
		reverse(&head);
	}
	else
	{

		while(curr_node != NULL)
		{
		
			if(k == 0)
			{
				new_last_node = prev_node;
				new_head  = curr_node; 

			}

			prev_node = curr_node;
			curr_node = curr_node->next;
			k--;
		}


		/*
		To rotate the list, set 
		next of kth node to NULL, 
		next of last node to previous head node, 
		and finally change head to (k+1)th node. 
		*/
		new_last_node->next = NULL;
		prev_node->next = head;
		head = new_head;
	}



	return head;

}