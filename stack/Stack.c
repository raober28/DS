#include"stack.h"


/*createStack: creates a stack of given capacity*/
struct Stack *createStack(unsigned capacity)
{
	struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));

	if(!stack)
		return NULL;
	
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int *)malloc(stack->capacity * sizeof(int));

	if(!stack->array)
		return NULL;
	
	return stack;
}

/*isFull: Stack if full when top is equal to last index*/
int isFull(struct Stack *stack)
{
	return stack->top == stack->capacity - 1;
}

/*isEmpty: Stack is empty when top is equal to -1*/
int isEmpty(struct Stack *stack)
{
	return stack->top == -1;
}


/*push:	adds an item to stack*/
void push(struct Stack *stack, int n)
{
	if(isFull(stack))
	{
		printf("error: stack overflow");
		return;
	}

	stack->array[++stack->top]	= n;
	printf("%d pushed to stack \n", n);
}

/*pop: removes an item from stack*/
int pop(struct Stack *stack)
{
	if(isEmpty(stack))
	{
		printf("error: stack underflow");
		return INT_MIN;
	}

	return stack->array[stack->top--];
}

/*peek: return top from stack without removing it*/
int peek(struct Stack *stack)
{
	if(isEmpty(stack))
	{
		printf("warning: stack empty");
		return INT_MIN;
	}

	return stack->array[stack->top];
}

