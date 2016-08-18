#include<stdio.h>
#include<stdlib.h>


#define true  1
#define false 0


/*node: a domain model representing a node in a Linked List*/
struct node {
	int data;
	struct node *next;
};


struct node * new_node(int n);

void print(char msg[]);
void printList(struct node *n);

int length_of_loop(struct node *loop_node);


int make_no_Out_of_list(struct node *head);


struct node *skip_first_n_nodes(struct node *head, int n);
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


struct node * fetch(struct node *head, int n);


struct node *reverse_in_group (struct node *head, int k);


int detectAndRemoveLoop(struct node *head);

void removeLoop(struct node *loop_node, struct node *head);

void removeLoop_Optimised(struct node * loop_node, struct node *head);


struct node *add_Linked_list(struct node *first, struct node *second);

