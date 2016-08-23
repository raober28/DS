#include <stdio.h>
#include <stdlib.h>


/*structure of a node*/
struct node 
{
	int data;
	struct node *next;
};

void printList(struct node *head);

struct node *new_node(int n);
void push(struct node **head_ref, int n);
void split(struct node **tail,struct node **first_tail, struct node **second_tail);