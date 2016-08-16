#include"ds.h"



void print(char msg[]) {
	printf("\n\n%75s\n",msg);
}


/*printList: prints all the elements in the LinedList*/
void printList(struct node *n)
{
	while(n != NULL)
	{
		printf("%d%s", n->data, (n->next != NULL)?" -> ":"");
		n = n->next;
	}
	printf("\n");
}



struct node * fetch(struct node *head, int n)
{

	while(head != NULL && n > 1)
	{
		head = head->next;
		n--;
	}

	return head;
}


struct node *detectloop(struct node *head) 
{

	int loop = false;

	struct node *first_ptr, *second_ptr, *prev_ptr;

	first_ptr = second_ptr = head;

	/*no loop if list is empty or having single node*/
	if(first_ptr == NULL || first_ptr->next == NULL)
		return NULL;

	prev_ptr = first_ptr;
	first_ptr = first_ptr->next;
	second_ptr = second_ptr->next->next;






	while(first_ptr != NULL && first_ptr->next!= NULL && second_ptr != NULL)
	{		
		if(first_ptr == second_ptr)
		{
			loop = true;
			break;
		}
		
		prev_ptr = first_ptr;
		first_ptr = first_ptr->next;
		second_ptr = second_ptr->next->next;
	}


	if(loop)
		return prev_ptr;
	else
		return NULL;
}




int length_of_loop(struct node *loop_node) {

	unsigned int n = 1;
	struct node *curr_node = loop_node;

	while(curr_node->next != loop_node) {
		curr_node = curr_node->next;
		n++;
	}

	return n;
}



struct node *skip_first_n_nodes(struct node *head, int n) {

	while(head != NULL && n > 0)  {

		head = head->next;
		n--;
	}

	return head;
}

