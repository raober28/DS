#include<stdio.h>
#include<stdlib.h>



/*node: a domain model representing a node in a Linked List*/
struct node {
	int data;
	struct node *next;
};


void printList(struct node *n);

void push(struct node **head_ref ,int n);
void insert_After(struct node *prev_node,int n); 
void append(struct node ** head_ref, int n);

void deleteNode_by_key(struct node **head ,int n); 
