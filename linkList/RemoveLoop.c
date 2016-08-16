#include"ds.h"

/*detectAndRemoveLoop: detects is there any loop in the Linked List,
					   and removes the loop if there. */
int detectAndRemoveLoop(struct node *head)
{
	struct node *slow_ptr, *fast_ptr;

	slow_ptr = fast_ptr = head;

	while(slow_ptr != NULL && fast_ptr != NULL && fast_ptr->next != NULL)
	{
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;

		/*If slow_ptr and fast_ptr meet at some point 
		  then there is a loop */
		if(slow_ptr == fast_ptr)
		{
			removeLoop_Optimised(slow_ptr, head);

			return 1;
		}


	}

	return 0;
}



/*removeLoop: removes the loop in a circular linked list*/
void removeLoop(struct node *loop_node, struct node *head)
{
	struct node *ptr1;
	struct node *ptr2;


	ptr1 = head;

	while(1)
	{
		ptr2 = loop_node;

		while(ptr2->next != loop_node && ptr2->next != ptr1)
			ptr2 = ptr2->next;

		if(ptr2->next == ptr1)
			break;

		ptr1 = ptr1->next;
	}


	ptr2->next = NULL;
}


void removeLoop_Optimised(struct node * loop_node, struct node *head)
{
	struct node *ptr1, *ptr2;

	int l = length_of_loop(loop_node);

	printf("Loop Count : %d\n", l);

	ptr1 = head;

	ptr2  = skip_first_n_nodes(head, l);

	printf("Node after skipping %d node is %d\n",l, ptr2->data );


	while(ptr2 != ptr1)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	ptr2 = ptr2->next;

	while(ptr2->next != ptr1)
		ptr2 = ptr2->next;

	ptr2->next = NULL;
	
}



int main(int argc, char const *argv[])
{
	
	print("***********Testing Lost loop removal***********");

	struct node * temp1 = (struct node *)(malloc(sizeof(struct node)));
	struct node * temp2 = (struct node *)(malloc(sizeof(struct node)));
	struct node * temp3 = (struct node *)(malloc(sizeof(struct node)));
	struct node * temp4 = (struct node *)(malloc(sizeof(struct node)));
	struct node * temp5 = (struct node *)(malloc(sizeof(struct node)));
	struct node * temp6 = (struct node *)(malloc(sizeof(struct node)));
	struct node * temp7 = (struct node *)(malloc(sizeof(struct node)));
	struct node * temp8 = (struct node *)(malloc(sizeof(struct node)));
	struct node * temp9 = (struct node *)(malloc(sizeof(struct node)));
	struct node * temp10 = (struct node *)(malloc(sizeof(struct node)));


	temp1->data  =  1;
	temp2->data  =  2;
	temp3->data  =  3;
	temp4->data  =  4;
	temp5->data  =  5;
	temp6->data  =  6;
	temp7->data  =  7;
	temp8->data  =  8;
	temp9->data  =  9;
	temp10->data = 10;


	temp1->next  = temp2;
	temp2->next  = temp3;
	temp3->next  = temp4;
	temp4->next  = temp5;
	temp5->next  = temp6;
	temp6->next  = temp7;
	temp7->next  = temp8;
	temp8->next  = temp9;
	temp9->next  = temp10;
	temp10->next = temp7;
	

	int result = detectAndRemoveLoop(temp1);

	printf("There is a loop in the list: %s\n", (result == 1) ? "true": "false");

	result = detectAndRemoveLoop(temp1);

	printf("Now there is a loop in the list: %s\n", (result == 1) ? "true": "false");

	printList(temp1);

}