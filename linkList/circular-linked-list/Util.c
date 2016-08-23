#include"cll.h"


/*printList: prints the circular linked list
  tail:		 last inserted node in the circular linked list*/
void printList(struct node *tail)
{
	if(tail == NULL)
	{
		printf("warning: empty list\n");
		return;
	}

	struct node *temp = tail;
	
	if(tail != NULL)
	{
		do
		{
			temp = temp->next;
			printf("%d%s", temp->data, (temp != tail)?" -> ":"");
		}
		while(temp != tail);
	}

	printf("\n");
}

/*allocates memory for new node in memory and initialize it with data*/
struct node *new_node(int n)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = n;
	new_node->next = NULL;
}


void push(struct node **tail_ref, int n)
{
	struct node *new = new_node(n), *temp, *head;

	if(*tail_ref == NULL)
	{
		*tail_ref = new;
		(*tail_ref)->next = *tail_ref;
		return;
	}

	temp = *tail_ref;
	head = (*tail_ref)->next;

	temp->next = new;
	new->next = head;

	*tail_ref = new;
}

