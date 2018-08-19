#include <stdio.h>
#include <stdlib.h>

/*A Structure to represent a queue */
struct Queue {
	int front, rear, size;
	unsigned capacity;
	int *array;
};


struct Queue *createQueue(unsigned capacity);

int isEmpty(struct Queue *queue);
int isFull( struct Queue *queue);

int enqueue(struct Queue *queue, int n);
int dequeue(struct Queue *queue);

void printQueue(struct Queue *queue);
