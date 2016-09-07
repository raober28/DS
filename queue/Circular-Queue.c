#include "circular-queue.h"

/*createQueue: creates a queue with given capacity*/
struct CQueue* createQueue(unsigned capacity)
{
	struct CQueue *queue = (struct CQueue *) malloc(sizeof(struct CQueue));
	if(!queue)
		return NULL;

	queue->capacity = capacity;
	queue->array = malloc(queue->capacity * (sizeof(int)));
	if(!queue->array)
		return NULL;
	queue->size = 0;
	queue->front = queue->rear = -1;
}


int isFull(struct CQueue *queue)
{
	return queue->size == queue->capacity;
}


int isEmpty(struct CQueue *queue)
{
	return queue->size == 0;
}


/*enqueue: adds an item to the queue.
		   returns non-zero value for unsuccessfull operation, otherwise 0*/
int enqueue(struct CQueue *queue, int n)
{
	if(isFull(queue))
		return -1;

	if(isEmpty(queue))
		queue->front = 0;

	if(queue->rear + 1 == queue->capacity)
		queue->rear = 0;
	else
		queue->rear += 1;

	queue->array[queue->rear] = n;
	queue->size += 1;


	return 0;
}

/*dequeue: removes the front item from queue*/
int dequeue(struct CQueue *queue)
{	
	if(isEmpty(queue))
		return INT_MIN;

	int item = queue->front;
	if(queue->front + 1 == queue->capacity)
		queue->front = 0;
	else
		queue->front += 1;

	queue->size -= 1;

	return item;
}


/*front: returns the front element from queue wihtout deleting it*/
int front(struct CQueue *queue)
{
	if(isEmpty(queue))
		return INT_MIN;

	return queue->array[queue->front];
}


/*rear: returns the rear element from queue wihtout deleting it*/
int rear(struct CQueue *queue)
{
	if(isEmpty(queue))
		return INT_MIN;

	return queue->array[queue->rear];
}

/*printQueue: prints all elements of queue to the console*/
void printQueue(struct CQueue *queue)
{
	if(isEmpty(queue))
		return;
	
	int i = queue->front;

	while(1)
	{
		printf("%d%s", queue->array[i], (i == queue->rear)?"":"->");

		if(i == queue->rear)
			break;
		
		if(i + 1 == queue->capacity && i != queue->rear)
			i = 0;
		else
			i += 1;

	}

	printf("\n");
}