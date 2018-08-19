#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*A basic Node */
struct Node {
	int item;
	struct Node *next, *prev;
};

/*A basic deque implementation using doubly-linked list*/
struct Deque {
	struct Node *front, *rear;
};


struct Node *createNode(int n);


struct Deque *createQueue();


int isEmpty(struct Deque *queue);

int insertFront(struct Deque *queue, int n);
int insertLast(struct Deque *queue, int n);


int deleteFront(struct Deque *queue);
int deleteLast(struct Deque *queue);

int getFront(struct Deque *queue);
int getRear(struct Deque *queue);

void printQueue(struct Deque *queue);