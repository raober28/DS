#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/*stack using array*/
struct Special_Stack {
	int top;
	unsigned capacity;
	int *array;
	int *min_array;
};


struct Special_Stack *createStack(unsigned capacity);


int isFull(struct Special_Stack *stack);
int isEmpty(struct Special_Stack *stack);

void push(struct Special_Stack *stack, int n);


int pop(struct Special_Stack *stack);
int peek(struct Special_Stack *stack);

void printStack(struct Special_Stack *stack);

int getMin(struct Special_Stack* stack);




