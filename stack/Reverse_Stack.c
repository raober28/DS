#include"stack.h"

struct Stack *reverse_stack(struct Stack *stack, struct Stack *recursive_reverse)
{	
	while(stack->top != -1)
		push(recursive_reverse, pop(stack));
}


/*The idea is to hold all the values in Function Call Stack until the stack becomes empty
  When the stack becomes empty, insert all held items one by obe at the bottom of stack*/

/*insertAtBottom: inserts the given element at the bottom of stack*/
void insertAtBottom(struct Stack **top_ref, int item)
{	
	/*if stack is empty then insert it*/
	if(isEmpty(*top_ref))
		push(*top_ref, item);
	else
	{
		/*Hold all items in Function Call Stack until we
		  reach end of stack.*/
		int temp = pop(*top_ref);
		insertAtBottom(top_ref, item);
		
		/*Once the item is inserted at the bottom, push all 
		  the items held in Function Call Stack*/
		push(*top_ref, temp);
	}
}

/*recursive_reverse: recursive_reverse the given stack using insertAtBottom*/
void recursive_reverse(struct Stack **stack)
{
	if(!isEmpty(*stack))
	{
		/*Hold all items in Function Call stack until we 
		  reach end of the stack*/
		int temp = pop(*stack);
		recursive_reverse(stack);

		/*Insert all the items(held in Function Call Stack)
		  Every item is inserted at bottom */
		insertAtBottom(stack, temp);
	}
}

int main(int argc, char const *argv[])
{
	struct Stack *stack;

	stack   = createStack(10);
	
	push(stack, 10);
	push(stack, 9);
	push(stack, 8);
	push(stack, 7);
	push(stack, 6);
	push(stack, 5);
	push(stack, 4);
	push(stack, 3);
	push(stack, 2);
	push(stack, 1);

	printStack(stack);
	recursive_reverse(&stack);
	
	printStack(stack);


	return 0;
}