#include "stack_char.h"

/*createStack: creates a stack of given capacity*/
struct Stack *createStack(unsigned capacity)
{
	struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));

	if(!stack)
		return NULL;
	
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (char *)malloc(stack->capacity * sizeof(char));

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
void push(struct Stack *stack, char ch)
{
	if(isFull(stack))
	{
		printf("error: stack overflow\n");
		return;
	}

	stack->array[++stack->top]	= ch;
	printf("%c pushed to stack \n", ch);
}

/*pop: removes an item from stack*/
char pop(struct Stack *stack)
{
	if(isEmpty(stack))
	{
		printf("error: stack underflow\n");
		return CHAR_MIN;
	}

	printf(" pop from  stack \n");
	return stack->array[stack->top--];
}

/*peek: return top from stack without removing it*/
char peek(struct Stack *stack)
{
	if(isEmpty(stack))
	{
		printf("warning: stack empty\n");
		return CHAR_MIN;
	}

	return stack->array[stack->top];
}