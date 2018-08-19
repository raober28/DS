/*Program to implement a stack that supports findMiddle() and deleteMiddle() in O(1)*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


/*A Doubly Linked List node*/
struct DLLNode {
	struct DLLNode *prev;
	int data;
	struct DLLNode *next;
};

/*Stack implementation using dll that supports finddMiddle() in O(1)*/
struct stack {
	struct DLLNode *top;
	struct DLLNode *mid;
	int count;
};

/*createNode: creates a node in memory*/
struct DLLNode *createNode(int data)
{
	struct DLLNode *node  =  (struct DLLNode *)malloc(sizeof(struct DLLNode));

	if(!node)
		return NULL;

	node->data = data;
	node->prev = NULL;
	node->next = NULL;	

	return node;
}

/*createStack: creates a empty stack in memory*/
struct stack *createStack(void)
{
	struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
	if(!stack)
		return NULL;

	stack->top = NULL;
	stack->mid = NULL;
	stack->count = 0;

	return stack;
}

/*isEmpty: checks if the stack is empty or node*/
int isEmpty(struct stack *stack)
{
	return (stack->count == 0);
}


/*push: inserts a node on the top of stack and  updated mid accordingly*/
int push(struct stack *stack, int n)
{
	struct DLLNode *node = createNode(n);
	if(!node)
		return -1;

	/*Since we are adding at begiging, prev will always be NULL*/
	node->prev = NULL;
	
	/*make the current top next of new node*/
	node->next = stack->top;

	/*increment the count of itmes in stack*/
	stack->count += 1;

	/*if the stack was empty then mid will point to new node*/
	if(stack->count == 1)
		stack->mid = node;
	else
	{
		stack->top->prev = node;
		
		/*Update mid after gap of one noe*/
		if(stack->count % 2 == 1)
			stack->mid = stack->mid->prev;
	}
	
	/*move top to poin to the new noe*/
	stack->top = node;

	return 0;
}

/*pop: removes the top element from stack*/
int pop(struct stack* stack)
{
	if(isEmpty(stack))
	{
		printf("error: stack underflow\n");
		return INT_MIN;
	}

	/*backing top node*/
	struct DLLNode *temp = stack->top;
	int tempData = stack->top->data;
	
	/*uppate top to point to the next node*/
	stack->top = stack->top->next;
	
	/*if stack does not becomes empty then updates prev of new top as NULL*/
	if(stack->top != NULL)
		stack->top->prev = NULL;

	stack->count -= 1;

	/*update the mid pointer when we have even number of
	  elements in the stack, i,e move down the mid pointer.*/
	if(stack->count % 2 == 0)
		stack->mid = stack->mid->next;

	free(temp);
	return tempData;
}

/*findMiddle: Find the Middle element of the stack*/
int findMiddle(struct stack *stack)
{
	if(isEmpty(stack))
	{
		printf("warning: stack underflow\n");
		return INT_MIN;
	}

	return stack->mid->data;
}


/*deleteMiddle: removes the middle element from stack*/
int deleteMiddle(struct stack* stack)
{
	if(isEmpty(stack))
	{
		printf("warning: stack underflow\n");
		return 0;
	}
	
	struct DLLNode *temp = stack->mid;
	
	/*when stack has only one element than */
	if(stack->mid->next == NULL)
		{
			stack->top = NULL;
			stack->mid = NULL;
		}
	else
	{	
		stack->mid->prev->next = stack->mid->next;
		stack->mid->next->prev = stack->mid->prev;

		if((stack->count) & 1)
			stack->mid = stack->mid->prev;
		else
			stack->mid = stack->mid->next;
		
		free(temp);
	}
	stack->count -= 1;
	return 1;
}

void printStack(struct stack *stack)
{
	struct DLLNode *node = stack->top;
	
	while(node)
	{
		printf("%s%d%s", (node->prev == NULL)?"[":"", node->data, (node->next == NULL)?"]":", ");
		node = node->next;
	}

	printf("\n");
}


int main()
{
    /* Let us create a stack using push() operation*/
    struct stack *stack = createStack();
    
    push(stack, 11);
    printf("stack->top : %d, stack->mid: %d\t", stack->top->data, findMiddle(stack));
    printStack(stack);
    
    push(stack, 22);
    printf("stack->top : %d, stack->mid: %d\t", stack->top->data, findMiddle(stack));
    printStack(stack);


    push(stack, 33);
    printf("stack->top : %d, stack->mid: %d\t", stack->top->data, findMiddle(stack));
    printStack(stack);

    push(stack, 44);
    printf("stack->top : %d, stack->mid: %d\t", stack->top->data, findMiddle(stack));
    printStack(stack);


    push(stack, 55);
    printf("stack->top : %d, stack->mid: %d\t", stack->top->data, findMiddle(stack));
    printStack(stack);



    push(stack, 66);
    printf("stack->top : %d, stack->mid: %d\t", stack->top->data, findMiddle(stack));
    printStack(stack);
    
    push(stack, 77);
 	printf("stack->top : %d, stack->mid: %d\t", stack->top->data, findMiddle(stack));
    printStack(stack);

    //printf("Item popped is %d\n", pop(stack));
    //printf("Item popped is %d\n", pop(stack));
    //printStack(stack);

    //printf("Middle Element is %d\n", findMiddle(stack));

    deleteMiddle(stack);
    printf("delet Middle\n");
    printf("stack->top : %d, stack->mid: %d\t", stack->top->data, findMiddle(stack));
    printStack(stack);


    return 0;
}



