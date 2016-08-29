#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>


struct Stack {
	int top;
	unsigned capacity;
	char *array;
};

struct Stack *createStack(unsigned capacity);

int isFull(struct Stack *stack);
int isEmpty(struct Stack *stack);

void push(struct Stack *stack, char ch);
char pop(struct Stack *stack);

char peek(struct Stack *stack);

void reverse(char *str);

int is_balanced_parantheses(char *expr);