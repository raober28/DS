#include"queuel.h"


/*createNode: allocates memory for new node*/
struct Node *createNode(int n)
{
	struct Node *node = (struct Node *)(malloc(sizeof(struct Node)));
	
	if(!node)
		return NULL;

	node->item = n;
	node->next = NULL;

	return node;
}

/*createQueuel: allocates memory for new queue*/
struct Queuel *createQueue()
{
	struct Queuel *queue = (struct Queuel *)(malloc(sizeof(struct Queuel)));

	if(!queue)
		return NULL;

	queue->size  = 0;
	queue->front = queue->rear = NULL;
	return queue;
}


int isEmpty(struct Queuel *queue)
{
	return queue->size == 0;
}



/*enqueue: adds an item at the rear of queue
	       return non-zero for any unsuccessfully operation, 0 for success*/
int enqueue(struct Queuel *queue, int n)
{
	struct Node *new_node = createNode(n);

	if(isEmpty(queue))
	{
		queue->front = queue->rear = new_node;
	}
	else
	{
		queue->rear->next = new_node;
		queue->rear = new_node;
	}

	queue->size += 1;

	return 0;
}


/*dequeue: removes an item from front of queue and returns it, 
		    return INT_MIN if queue is empty*/
int dequeue(struct Queuel *queue)
{
	if(isEmpty(queue))
		return INT_MIN;

	struct Node *node = queue->front;
	int item = node->item;

	queue->front = queue->front->next;

	if(queue->front == NULL)
		queue->rear = NULL;

	queue->size -= 1;

	free(node);
	return item;
}

int front(struct Queuel *queue)
{
	if(isEmpty(queue))
		return INT_MIN;
	
	return queue->front->item;
}


int rear(struct Queuel *queue)
{	
	if(isEmpty(queue))
		return INT_MIN;

	return queue->rear->item;
}


void printQueueL(struct Queuel *queue)
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