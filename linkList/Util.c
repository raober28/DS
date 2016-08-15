#include"ds.h"

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

