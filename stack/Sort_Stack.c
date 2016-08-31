#include"stack.h"


void put(struct Stack *stack, int item);


/*sort_stack: sorts the stack in place*/
void sort_stack(struct Stack *stack)
{
	if(!isEmpty(stack))
	{
		int temp = pop(stack);
		sort_stack(stack);
		put(stack, temp);
	}
	
}

/*put: puts the new item into stack into sorted order,
		expects the given stack need to be in sorted order*/
void put(struct Stack *stack, int item)
{
	if(isEmpty(stack) || item >= peek(stack))
		push(stack, item);
	else
	{
		int temp = pop(stack);
		put(stack, item);
		
		push(stack, temp);
	}
}


int main(int argc, char const *argv[])
{
	struct Stack *stack;

	stack   = createStack(10);
		
	push(stack, 30);
	push(stack, -5);
	push(stack, 18);
	push(stack, 14);
	push(stack, -3);
	push(stack, 51);
	push(stack, 45);
	push(stack, 73);
	push(stack, 29);
	push(stack, 11);

	printStack(stack);
	sort_stack(stack);
	
	printStack(stack);


	return 0;
}