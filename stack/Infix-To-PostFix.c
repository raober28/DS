#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stack {
	int top;
	unsigned capacity;
	int *array;
};

 struct stack *create_stack(unsigned capacity)
 {
 	struct stack *stack = (struct stack *)malloc(sizeof(struct stack));
 	
 	if(!stack)
 		return NULL;

 	stack->top	 = -1;
 	stack->capacity = capacity;
 	stack->array  = (int *)malloc(stack->capacity  * sizeof(int));

 	if(!stack->array)
 		return NULL;
 	
 	return stack;
 }


 int isEmpty(struct stack *stack)
 {
 	return stack->top == -1;
 }

 int isFull(struct stack *stack)
 {
 	return stack->top == stack->capacity;
 }


 void push(struct stack *stack, char op)
 {
 	if(isFull(stack))
 	{
 		printf("error: stack overflow");
 		return;
 	}

 	stack->array[++stack->top] = op;

 }


 char pop(struct stack* stack)
 {
 	if(!isEmpty(stack))
 		return stack->array[stack->top--];

 	return '$'; 	
 }


 char peek(struct stack* stack)
 {
 	if(!isEmpty(stack))
 		return stack->array[stack->top];

 	return '$';
 }


 int isOperand(char ch)
 {
 	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
 }

 int prec(char ch)
 {
 	switch(ch)
 	{
 		case '+':
 		case '-':
 			return 1;

 		case '*':
 		case '/':
 			return 2;

 		case '^':
 			return 3;
 	}
 		return -1;			
 }


 char *infix_to_prefix(char * exp)
 {
 	struct stack *stack = create_stack(strlen(exp));

 	int i , k;

 	if(!stack)
 		return NULL;

 	for(i = 0, k = -1; exp[i]; i++)
 	{
 		if(isOperand(exp[i]))
 		{
 			exp[++k] = exp[i];
 		}

 		else if(exp[i] == '(')
 		{
 			push(stack, exp[i]);
 		}

 		else if(exp[i] == ')')
 		{
 			while(!isEmpty(stack) && peek(stack) != '(')
 				exp[++k] = pop(stack);

 			if(!isEmpty(stack)	&& peek(stack) != '(')
 				return  NULL;
 			else
 				pop(stack);
 		}

 		else 
 		{
 			while (!isEmpty(stack) && prec(exp[i]) <= prec(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
 		}
 	}

 	
 	while (!isEmpty(stack))
        exp[++k] = pop(stack );

 	exp[++k] = '\0';
 	printf("%s\n", exp);

 	return exp;

 }


 int main()
{
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infix_to_prefix(exp);
    return 0;
}