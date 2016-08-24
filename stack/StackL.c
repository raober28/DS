#include "stackl.h"

/*createStack: creates a new stack */

struct frame* createframe(int n)
{
	struct frame *new = (struct frame*)malloc(sizeof(struct frame));
	new->data = n;
	new->next = NULL;

	return new;

}

struct StackL* createStack(void)
{
	struct StackL *stackl = (struct StackL*)malloc(sizeof(struct StackL));
	stackl->top = NULL;

	return stackl;
}


/*isEmpty: checks if stack is empty or not*/
int isEmpty(struct StackL *stackl)
{
	return (stackl->top == NULL);
}



/*push: adds a new element at the top of stack*/
void push(struct StackL *stackl, int n)
{
	struct frame *new = createframe(n);

	new->next = stackl->top;
	stackl->top = new;

	printf("%d pushed to stack \n", n);

}

/*pop: removes the top element from stack and returns it*/
struct frame *pop(struct StackL *stackl)
{
	if(isEmpty(stackl))
	{
		printf("error: stack underflow");
		return NULL;
	}

	struct frame *node = stackl->top;

	stackl->top = stackl->top->next;
	
	printf("%d popped from stack \n", node->data);

	return node;
}


/*peek: returns the top element from stack without removing it*/
struct frame *peek(struct StackL * stackl)
{
	if(isEmpty(stackl))
	{
		printf("error: stack underflow\n");
		return NULL;
	}

	struct frame *node = stackl->top;
	printf("Top item is %d\n",node->data);
	return node;
}


