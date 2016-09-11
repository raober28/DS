#include "kqueues.h"

 /*A data structure kQueues that represents k queues. 
   Implementation of kQueues should use only one array, i.e., 
   k queues should use the same array for storing elements
*/


/*createKQueue: allocates memory for K queues in memory of size n*/
struct KQueue *createKQueue(int capacity, int k)
{
	struct KQueue *kqueue = (struct KQueue *)malloc(sizeof(struct KQueue));
	if(!kqueue)
		return NULL;

	kqueue->capacity = capacity;
	kqueue->k = k;
	kqueue->arr = (int *)malloc(sizeof(int) * kqueue->capacity);

	if(!kqueue->arr)
		return NULL;

	kqueue->front = (int *)malloc(sizeof(sizeof(int) * k));
	kqueue->rear  = (int *)malloc(sizeof(sizeof(int) * k));

	if(!kqueue->front || !kqueue->rear)
		return NULL;

	kqueue->next = (int *)malloc(sizeof(sizeof(int) * kqueue->capacity));

	if(!kqueue->next)
		return NULL;

	int i;

	//Inititalize all queues as empty
	for(i = 0;i < k; i++)
		kqueue->front[i] = -1;
	
	//Inititalize all spaces as free
	kqueue->free = 0;

	for(i = 0; i < capacity-1; i++)
		kqueue->next[i] = i+1;

	kqueue->next[capacity-1] = -1;	//-1 is used to indicate end of free list

	return kqueue;
}


/*isFull: to check if queue is full or not*/
int isFull(struct KQueue *queue)
{
	return queue->free == -1;
}

/*isEmpty: to check if k'th queue is empty or not*/
int isEmpty(struct KQueue *queue, int k)
{
	return queue->front[k] == -1;
}


/*enqueue: To add an item in k'th queue wher k's value should be from 0 to k-1*/
void enqueue(struct KQueue *queue, int k, int item)
{	
	if(k < 0 && k > (queue->k - 1))
	{
		printf("warning: invalid queue no\n");
		return;
	}

	//Overflow Check
	if(isFull(queue))
	{
		printf("warning: queue overflow\n");
		return;
	}


	int i = queue->free, temp;			//Store index of first free slot

	queue->free = queue->next[i];		//update free's index to point to next free location in queue

	if(isEmpty(queue, k))
	{
		queue->front[k] = i;
	}
	else
	{
		temp = queue->rear[k];
		queue->next[temp] = i;
	}
	
	queue->next[i] = -1;				//Making next of new rear -1
	
	//update rear of k'th queue to point to new rear
	queue->rear[k] = i;

	//Put the item in array
	queue->arr[i] = item;
}


/*dequeue: removes the rear element from k'th queue*/
int dequeue(struct KQueue *queue, int k)
{	
	if(k < 0 && k > (queue->k - 1))
	{
		printf("warning: invalid queue no\n");
		return -1;
	}

	//Underflow Check
	if(isEmpty(queue, k))
	{
		printf("warning: queue underflow\n");
		return -1;
	}

	/*Find the index of front item in k'th queue*/
	int i = queue->front[k];
	
	/*Make front of k'th queue to point to new front*/
	queue->front[k] = queue->next[i];
	
	/*Attach the previous front to the begining of free list*/
	queue->next[i] = queue->free;
	queue->free = i;

	//return the previous front item
	return queue->arr[i];
}


void printQueue(struct KQueue *queue, int k)
{
	if(isEmpty(queue, k))
		return;

	int i = queue->front[k];

	//iterate until queue is empty, end of queue is denoted by -1
	while(i != -1)
	{
		//printf("%d%s", queue->arr[i], queue->next[i] == -1?"":"->");
		printf("%d%s", queue->arr[i], "->");
		i = queue->next[i];
	}

	printf("\n");
}




