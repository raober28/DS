#include "queue_of_treeNodes.h"

/*createTreeNode: Allocates the memory for the Node*/
TNode *createTreeNode(int data)
{
	TNode *node = (TNode *)malloc(sizeof(TNode));

	if(node == NULL)
		return NULL;
	
	node->data  = data;
	node->left  = node->right = NULL;

	return node;
}	


/*createQueue: Allocates memory for queue*/
Queue *createQueue(unsigned capacity)
{
	Queue *queue = (Queue *)malloc(sizeof(Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;	//Initially the queue is empty
	queue->rear = capacity -1;
	queue->array = (TNode **)malloc(queue->capacity * sizeof(TNode *));
	return queue;
}


/*isEmpty: checks if queue is empty or not*/
int isEmpty(Queue *queue)
{
	return queue->size == 0;
}

/*isFull: checks if queue is full or not*/
int isFull(Queue *queue)
{
	return queue->size == queue->capacity;
}


/*enqueue: adds a new node at the rear of queue
		   returns -1 if unsuccessful, otherwise 0*/
int enqueue(Queue *queue, TNode *tNode)
{	
	if(isFull(queue))
		return -1;

	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = tNode;
	queue->size++;
	return 0;
}


/*dequeue: removes the front node from queue*/
TNode *dequeue(Queue *queue)
{
	if(isEmpty(queue))
		return NULL;
	
	TNode *item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size--;
	return item;
}
