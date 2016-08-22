#include <stdio.h>
#include <stdlib.h>

/*Node of a doubly linked list*/
struct node {

	int data;

	struct node *next;	//Pointer to next node in DLL
	struct node *prev;	//Pointer to previous node in DLL
};


void printList(struct node *n);
struct node *new_node(int n);

void push(struct node **head_ref, int n);
void insert_after(struct node **prev_node, int n);
void append(struct node **head_ref, int n);
void insert_before(struct node **next_node, int n);


void delete(struct node **curr_node);