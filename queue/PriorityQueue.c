#include "priority_queue.h"

/*createNode: allocates memory for a node*/
struct Node *createNode(int item, int priority)
{
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));

	if(!node)
		return NULL;

	node->item = item;
	node->priority = priority;
	node->next = NULL;

	return node;
}

/*createQueue: allocates memory for priorty queue*/
struct P_Queue *createQueue()
{
	struct P_Queue *queue = (struct P_Queue *)malloc(sizeof(struct P_Queue));

	if(!queue)
		return NULL;

	queue->front = queue->rear = NULL;	

	return queue;
}


int isEmpty(struct P_Queue *queue)
{
	return queue->front == NULL;
}


/*insert: Inserts an item with given priority.*/
int insert(int item, int priority, struct P_Queue *queue)
{
	struct Node *new_node = createNode(item, priority);

	if(isEmpty(queue))
		queue->front = queue->rear = new_node;
	else
	{
		queue->rear->next = new_node;
		queue->rear = new_node;
	}

}

/*getHighestPriority:returns the highest priority node in the queue*/
struct Node *getHighestPriority(struct P_Queue *queue)
{
	if(isEmpty(queue))
		return NULL;

	int max = INT_MIN;
	struct Node *maxNode = NULL, *node;

	node = queue->front;

	while(node)
	{
		if(node->item > max)
		{
			max = node->item;
			maxNode = node;
		} 

		node = node ->next;
	}

	return maxNode;
} 


/*deleteHighestPriority: removes the highest priority item from the queue
						 returns non-zero for non-successfull operation, otherwise zero */
int deleteHighestPriority(struct P_Queue *queue)
{
	if(isEmpty(queue))
		return -1;

	int max = INT_MIN;
	struct Node *maxNode, *node, *prevNode;

	maxNode = prevNode =  node = queue->front;

	/*if queue has only one element, removes it*/
	if(node->next == NULL)
	{
		queue->front = queue->rear = NULL;
		return 0;
	}

	max = node->priority;

	while(node->next)
	{
		if(node->next->priority > max)
		{
			max = node->next->priority;
			maxNode = node->next;
			prevNode = node;
		} 

		node = node ->next;
	}

	/*if queue's first element is the highest priority node,*/
	if(maxNode == queue->front)
		queue->front = queue->front->next;
	else
		prevNode->next = maxNode->next;

	return 0;
}

/*printQueue: prints all the elements of queue*/
void printQueue(struct P_Queue *pqueue)
{
	if(!pqueue)
		return;

	struct Node *node = pqueue->front;
	
	while(node)
	{
		printf("(%d,%d)%s", node->item, node->priority, (node->next)?"->":"");
		node = node->next;
	}
	printf("\n");	
}
