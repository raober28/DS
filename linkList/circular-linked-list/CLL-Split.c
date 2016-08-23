#include "cll.h"

void split(struct node **tail,struct node **first_tail, struct node **second_tail)
{
	struct node *head, *first_ptr, *second_ptr, *second_head;
	
	if(*tail == NULL)
	{
		printf("warning: empty list\n");
		return;
	}

	head = (*tail)->next;
	first_ptr = second_ptr = head;

	
	/*iterate through out the list*/
	while(second_ptr->next !=head && second_ptr->next->next != head)
	{
		first_ptr = first_ptr->next;
		second_ptr = second_ptr->next->next;
	}


	*first_tail =  first_ptr;
	second_head =  first_ptr->next;

	(*first_tail)->next = head;
	second_ptr->next = second_head;

	*second_tail = second_ptr;
	

}