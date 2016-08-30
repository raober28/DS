#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/*stack using array*/
struct Stack {
	int top;
	unsigned capacity;
	int *array;
};


struct Stack *createStack(unsigned capacity);


int isFull(struct Stack *stack);
int isEmpty(struct Stack *stack);

void push(struct Stack *stack, int n);


int pop(struct Stack *stack);
int peek(struct Stack *stack);

void printStack(struct Stack *stack);

char *reverse(char *str);

void recursive_reverse(struct Stack **stack);


void strcatR(char *src, char *des);



