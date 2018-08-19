#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*A basic Node */
struct Node {
	int item;
	struct Node *next;
};

/*A basic queue implementation using linked list*/
struct Queuel {
	int size;
	struct Node *front, *rear;
};



struct Node *createNode(int n);
struct Queuel *createQueue();

int isEmpty(struct Queuel *queue);

int enqueue(struct Queuel *queue, int n);
int dequeue(struct Queuel *queue);

int front(struct Queuel *queue);
int rear(struct Queuel *queue);

void printQueueL(struct Queuel *queue);