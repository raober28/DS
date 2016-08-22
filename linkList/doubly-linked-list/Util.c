#include "dll.h"

struct node *new_node(int n)
{
	struct node *node = (struct node *)malloc(sizeof(struct node));

	node->data = n;
	node->next = NULL;
	node->prev = NULL;
}



void printList(struct node *n)
{
	while(n != NULL)
	{
		printf("%d%s", n->data, (n->next != NULL)?" -> ":"");
		n = n->next;
	}
	printf("\n");
}
