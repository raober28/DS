#include <stdio.h>
#include <stdlib.h>
#define N 100

/*A Single Node representation*/
typedef struct treeNode {
	int data;
	struct treeNode *left, *right;
}TNode;


/*A Queue of Nodes implemented using array*/
typedef struct queue {
	int front, rear, size;
	unsigned capacity;
	TNode **array;
}Queue;


TNode *createTreeNode(int data);	
Queue *createQueue(unsigned capacity);

int isEmpty(Queue *queue);
int isFull(Queue *queue);


int enqueue(Queue *queue, TNode *tNode);
TNode *dequeue(Queue *queue);