#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*A simple structure to implement a circular queue*/
struct CQueue
{
	int front, rear, size;
	unsigned capacity;
	int *array;
};

struct CQueue* createQueue(unsigned capacity);

int isFull(struct CQueue *queue);
int isEmpty(struct CQueue *queue);


int enqueue(struct CQueue *queue, int n);
int dequeue(struct CQueue *	queue);
