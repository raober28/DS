#include"ds.h"

struct node * merge(struct node * l_head, struct node * r_head)
{
	struct node *head, *curr_left, *curr_right, *curr_node;

	if(l_head == NULL)
		return r_head;

	if(r_head == NULL)
		return l_head;

	curr_left  = l_head;
	curr_right = r_head;


	if(l_head->data < r_head->data)
	{
		head = curr_node = l_head;
		curr_left = l_head->next;
	}
	else
	{
		head = curr_node = r_head;
		curr_right = r_head->next;

	}

	

	while(curr_left != NULL && curr_right != NULL)
	{
		if(curr_left->data < curr_right->data)
		{
				curr_node->next = curr_left;
				curr_left = curr_left->next;
		}
		else
		{
			curr_node->next = curr_right;
			curr_right = curr_right->next;
		}

		curr_node = curr_node->next;
	}

	if(curr_left == NULL)
		curr_node->next = curr_right;

	if(curr_right == NULL)
		curr_node->next = curr_left;


	return head;
}