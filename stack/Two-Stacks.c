#include"two-stacks.h"


/*create_stack: create two stack from extreme corner of array[]*/
struct two_stack *create_stack(int capacity)
{
	struct two_stack *stack = (struct two_stack *)malloc(sizeof(struct two_stack));

	if(!stack)
		return NULL;

	stack->capacity = capacity;

	stack->top1 = -1;
	stack->top2 = capacity;

	stack->array =  (int *)malloc(sizeof(int) * capacity);

	if(!stack->array)
		return NULL;

	return stack;
}

/*push1: pushes new data in first stack,
		 overflow when it reaches the second stack region*/
int push1(struct two_stack *stack, int n)
{
	if(stack->top1 < (stack->top2)-1)
	{
		stack->array[++stack->top1] = n;
		printf("pushed element in stack1 = %d\n", n);
		return 0;
	}
	else 
	{
		printf("error: stack overflow\n");
		return -1;
	}
	
}



/*push2: pushes new data in second stack,
		 overflow when it reaches the first stack region*/
int push2(struct two_stack *stack, int n)
{
	if(stack->top2 > (stack->top1 + 1))
	{
		stack->array[--stack->top2] = n;
		printf("pushed element in stack2 = %d\n", n);
		return 0;
	}
	else
	{
		printf("error: stack overflow\n");
		return -1;
	
	}
		
}


void peek1(struct two_stack *stack)
{
	if(stack->top1 == -1)
		printf("stack1 empty\n");
	else
		printf("top element in stack1 = %d\n", stack->array[stack->top1]);
	
}


void peek2(struct two_stack *stack)
{
	if(stack->top2 ==  stack->capacity)
		printf("stack2 empty\n");
	else
		printf("top element in stack2 = %d\n", stack->array[stack->top2]);

}



int pop1(struct two_stack *stack)
{
	if(stack->top1 == -1)
	{
		printf("error: stack underflow\n");
		return -1;
	}

	return stack->array[stack->top1--];

}


int pop2(struct two_stack *stack)
{
	if(stack->top2 ==  stack->capacity)
	{
		printf("error: stack underflow\n");
		return -1;
	}

	return stack->array[stack->top2++];

}



