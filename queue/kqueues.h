#include <stdio.h>
#include <stdlib.h>

struct KQueue {
	int capacity, k;
	int *arr;			//Array of size n to store actual contents to be stored in queue
	int *rear;			//Array of size k to store indexes of front elements of queue
	int *front;			//Array of size k to store indexes of rear elements of queue
	int  *next;			//Array of size n to store next entry in all queues
	int free; 			//To store begining index of free list
};

struct KQueue *createKQueue(int capacity, int k);
int isFull(struct KQueue *queue);
int isEmpty(struct KQueue *queue, int k);
void enqueue(struct KQueue *queue, int k, int item);
int dequeue(struct KQueue *queue, int k);
void printQueue(struct KQueue *queue, int k);