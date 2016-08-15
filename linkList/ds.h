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
void deleteNode_by_Pos(struct node **head,int pos);




int getCount(struct node * head);

int getCountR(struct node * head);

void swap(struct node ** head, int x, int y);
void reverse(struct node **head_ref);


struct node * merge(struct node * l_head, struct node * r_head);

