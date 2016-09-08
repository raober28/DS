#include "deque.h"


/*createNode: allocates memory for new node*/
struct Node *createNode(int n)
{
	struct Node *node = (struct Node *)(malloc(sizeof(struct Node)));
	
	if(!node)
		return NULL;

	node->item = n;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

/*createQueuel: allocates memory for new queue*/
struct Deque *createQueue()
{
	struct Deque *queue = (struct Deque *)(malloc(sizeof(struct Deque)));

	if(!queue)
		return NULL;

	queue->front = queue->rear = NULL;
	return queue;
}


int isEmpty(struct Deque *queue)
{
	return queue->front == 0;
}


/*insertFront: adds an item at the front of queue
	       return non-zero for any unsuccessfully operation, 0 for success*/
int insertFront(struct Deque *queue, int n)
{
	struct Node *new_node = createNode(n);

	if(isEmpty(queue))
		queue->front = queue->rear = new_node;
	else
	{
		new_node->next = queue->front;
		queue->front->prev = new_node;
		queue->front = new_node;
	}

	return 0;
}


/*insertLast: adds an item at the rear of queue
	       return non-zero for any unsuccessfully operation, 0 for success*/
int insertLast(struct Deque *queue, int n)
{
	struct Node *new_node = createNode(n);

	if(isEmpty(queue))
	{
		queue->front = queue->rear = new_node;
	}
	else
	{
		queue->rear->next = new_node;
		new_node->prev = queue->rear;
		queue->rear = new_node;
	}

	return 0;
}

/*deleteFront: removes an item from front of queue and returns it, 
		    return INT_MIN if queue is empty*/
int deleteFront(struct Deque *queue)
{
	if(isEmpty(queue))
		return INT_MIN;

	struct Node *node = queue->front;
	int item = node->item;


	queue->front = queue->front->next;

	queue->front->prev = NULL;


	if(queue->front == NULL)
		queue->rear = NULL;

	free(node);
	return item;
}


/*deleteLast: removes an item from front of queue and returns it, 
		    return INT_MIN if queue is empty*/
int deleteLast(struct Deque *queue)
{
	if(isEmpty(queue))
		return INT_MIN;

	struct Node *node = queue->rear;
	int item = node->item;

	queue->rear = queue->rear->prev;
	queue->rear->next = NULL;

	if(queue->rear == NULL)
		queue->front = NULL;

	free(node);
	return item;
}



int getFront(struct Deque *queue)
{
	if(isEmpty(queue))
		return INT_MIN;
	
	return queue->front->item;
}


int getRear(struct Deque *queue)
{	
	if(isEmpty(queue))
		return INT_MIN;

	return queue->rear->item;
}


void printQueue(struct Deque *queue)
{
	if(isEmpty(queue))
		return;

	struct Node *node = queue->front;

	while(node)
	{
		printf("%d%s", node->item, (node->next == NULL)? "": "->");
		node = node->next;
	}

	printf("\n");
}