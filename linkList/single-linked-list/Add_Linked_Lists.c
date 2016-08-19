#include"ds.h"


/*add_Linked_list: 	Adds contents of two linked lists and return head node of resultant list*/
struct node *add_Linked_list(struct node *first, struct node *second)
{

	int carry = 0, sum;

	struct node *head, *curr_node;
	
	int first_node = 0;

	while(first != NULL || second != NULL)	//while one of the lists exists
	{
		
		sum = carry + (first ? first->data : 0) + (second ? second->data : 0) ;
		
		carry = (sum >= 10) ? 1: 0;
		sum  = sum % 10;
	

		if(first_node == 0)
		{
			head = curr_node = new_node(sum);
			first_node = 1;
		} else{
			curr_node->next = new_node(sum);
			curr_node = curr_node->next;
		}


		if(first)  first =  first->next;
		if(second) second = second->next;
	
	}


	if(carry > 0)
		curr_node->next = new_node(carry);


	

	return head;

}