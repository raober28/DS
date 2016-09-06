#include"queue.h"

/*createQueue: create a queue with given capacity*/
struct Queue* createQueue(unsigned capacity)
{
	struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
	if(!queue)
		return NULL;

	queue->capacity = capacity;
	queue->front  = -1;
	queue->rear = -1;

	queue->array = (int *)malloc(queue->capacity * sizeof(int));

	return queue;
}

int isEmpty(struct Queue *queue)
{
	return queue->front == -1;
}

int isFull(struct Queue *queue)
{
	return queue->rear + 1 == queue->capacity;
}

int enqueue(struct Queue *queue, int n)
{
	if(isFull(queue))
	{
		printf("error: Queue Overflow\n");
		return -1;
	}

	if(isEmpty(queue))
		queue->front += 1;

	queue->rear +=1;
	queue->array[queue->rear] = n;

	return 0;
}


int dequeue(struct Queue *queue)
{
	if(isEmpty(queue))
	{
		printf("error: Queue Underflow\n");
		return -1;
	}

	if(isFull(queue) && (queue->front == queue->rear))
		{
			queue->front = -1;
			queue->rear = -1;
		}
	else
		queue->front += 1;
	
	return 0;
}


void printQueue(struct Queue *queue)
{
	int i;

	if(isEmpty(queue))
		return;

	for(i = queue->front ; i <= queue->rear; i++)
		printf("%d%s", queue->array[i], (i == queue->rear)?"":"->");

	printf("\n");
}