#include"special_stack.h"


/*createStack: creates a stack of given capacity*/
struct Special_Stack *createStack(unsigned capacity)
{
	struct Special_Stack *stack = (struct Special_Stack*)malloc(sizeof(struct Special_Stack));

	if(!stack)
		return NULL;
	
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int *)malloc(stack->capacity * sizeof(int));

	stack->min_array = (int *)malloc(stack->capacity * sizeof(int));

	if(!stack->array)
		return NULL;

	if(!stack->min_array)
		return NULL;
	
	return stack;
}

/*isFull: Stack if full when top is equal to last index*/
int isFull(struct Special_Stack *stack)
{
	return stack->top == stack->capacity - 1;
}

/*isEmpty: Stack is empty when top is equal to -1*/
int isEmpty(struct Special_Stack *stack)
{
	return stack->top == -1;
}


/*push:	adds an item to stack*/
void push(struct Special_Stack *stack, int n)
{
	if(isFull(stack))
	{
		printf("error: stack overflow");
		return;
	}

	if(isEmpty(stack))
		stack->min_array[stack->top + 1] = n;
	else
	{
	   stack->min_array[stack->top + 1] = (stack->min_array[stack->top] < n)? stack->min_array[stack->top]: n;
	}


	stack->array[++stack->top]	= n;
	//printf("%d pushed to stack \n", n);
}

/*pop: removes an item from stack*/
int pop(struct Special_Stack *stack)
{
	if(isEmpty(stack))
	{
		printf("error: stack underflow");
		return INT_MIN;
	}


	return stack->array[stack->top--];
}

/*peek: return top from stack without removing it*/
int peek(struct Special_Stack *stack)
{
	if(isEmpty(stack))
	{
		printf("warning: stack empty");
		return INT_MIN;
	}

	return stack->array[stack->top];
}


void printStack(struct Special_Stack *stack)
{
	int i = 0;

	printf("\n");
	for(i = stack->top ; i > -1; i--)
	{
		printf("%d %s",stack->array[i], (i != 0)?"->":"" );
	}

	printf("\n");
}

int getMin(struct Special_Stack* stack)
{
	return stack->min_array[stack->top];
}


