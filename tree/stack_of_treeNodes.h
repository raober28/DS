#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

typedef struct stack {
	int top;
	int size;
	struct Node **array;
}Stack;




struct Node *createNode(int data);
Stack *createStack(int n);

int isEmpty(Stack *stack);
int isFull(Stack *stack);

int push(Stack *stack, struct Node *node);
struct Node *pop(Stack *stack);
struct Node *peek(Stack *stack);

