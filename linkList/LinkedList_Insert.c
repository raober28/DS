#include "ds.h"


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

/*push: inserts a new element in the begining of LinkedList
		complexity is O(1) as it inserts by just switching the head pointers	
*/
void push(struct node **head_ref ,int n) {

	struct node * new = (struct node *)malloc(sizeof(struct node));
	new->data = n;

	new->next = *head_ref;
	*head_ref = new;
}


/*insert_After: insert the new element after the given node in the Linked List
				complexity is o(1): as it only needs to rearrange prevous and next node*/
void insert_After(struct node *prev_node,int n) {

	
	if(prev_node == NULL)
	{
		printf("error: the given previous node cannot be null ");
		return;
	}

	
	struct node *new_node = (struct node *)(malloc(sizeof(struct node)));

	new_node->data = n;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}


/*apped: insert the given element at the last position in Linked List
		 complexity is o(n): as it needs to be transversed to get the last node in list*/
void append(struct node ** head_ref, int n) {

	struct node * new_node = (struct node *)(malloc(sizeof(struct node)));
	new_node->data = n;
	new_node->next = NULL;

	/*If the given list is empty, make the new element as head*/
	if(*head_ref == NULL) {
		*head_ref = new_node;
		return;
	}

	struct node * last = *head_ref;

	/*iterate till the last node*/
	while(last->next != NULL)
		last =	last->next;

	last->next = new_node;
	return;

}



