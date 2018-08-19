#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*A simple Node representation*/
struct Node
{
	int item;
	int priority;
	struct Node *next;
};

/*A Priority Queue structure*/
struct P_Queue {
	struct Node *front, *rear;
};


struct Node *createNode(int item, int priority);


struct P_Queue *createQueue();

int isEmpty(struct P_Queue *queue);

int insert(int item, int priority, struct P_Queue *pqueue);

struct Node *getHighestPriority(struct P_Queue *queue); 
int deleteHighestPriority(struct P_Queue *queue);

void printQueue(struct P_Queue *pqueue);
