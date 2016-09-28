#include "stack_of_treeNodes.h"

struct Node *createNode(int data)
{
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	node->data = data;
	node->left = node->right = NULL;

	return node;
}

/*createStack: We create a stack using array of pointers to Node */
Stack *createStack(int n)
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	stack->top = 1;
	stack->size = n;
	stack->array = (struct Node **)malloc(stack->size * sizeof(struct Node *));

	return stack;
}

int isEmpty(Stack *stack)
{
	return stack->top == 1;
}


int isFull(Stack *stack)
{
	return stack->top == stack->size;
}

int push(Stack *stack,struct Node *node)
{
	if(isFull(stack))
		return -1;

	stack->array[stack->top++] = node;

	return 0;
}

struct  Node *pop(Stack *stack)
{
	if(isEmpty(stack))
		return NULL;

	return stack->array[--stack->top];
}



struct Node *peek(Stack *stack)
{
	if(isEmpty(stack))
		return NULL;

	return stack->array[stack->top -1];
}