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

 /*isOperand: a utility function to check if the given character is operand*/
 int isOperand(char ch)
 {
 	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
 }

 /*prec: return precedence of a given character
 		 Higher returned value means high precedence*/
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


 /*infix_to_prefix: converts infix notation to postfix*/
 char *infix_to_prefix(char * exp)
 {
 	int i , k;
 	
 	/*create a stack equal to expression size*/
 	struct stack *stack = create_stack(strlen(exp));


 	if(!stack)	//checks if stack was created successfully
 		return NULL;

 	for(i = 0, k = -1; exp[i]; i++)
 	{
 		/*If the scanned character is operand, add it to output*/
 		if(isOperand(exp[i]))
 		{
 			exp[++k] = exp[i];
 		}

 		/*If the scanned character is an '(', push it to stack*/
 		else if(exp[i] == '(')
 		{
 			push(stack, exp[i]);
 		}

 		/*If the scanned character is an ')', pop and output from the stack
 		  until an '(' is encountered*/
 		else if(exp[i] == ')')
 		{
 			while(!isEmpty(stack) && peek(stack) != '(')
 				exp[++k] = pop(stack);

 			if(isEmpty(stack))
 			{
 				printf("error: invalid expression, matching opening brace for ')' does not found\n");
 				return NULL;
 			}

 			else if(!isEmpty(stack)	&& peek(stack) != '(')
 			{
			    printf("error: invalid expression\n");
 				return  NULL;	//invalid expression
 			}
 			else
 				pop(stack);	
 		}

 		else 	// an operator is encountered
 		{
 			while (!isEmpty(stack) && prec(exp[i]) <= prec(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
 		}
 	}

 	/*pop all the operators from stack */
 	while (!isEmpty(stack))
 	{	
 		if(peek(stack) == '(')
 		{
 			printf("error: invalid expression, matching closing brace for '(' does not found\n");
 			return NULL;
 		}
        exp[++k] = pop(stack);
 	}

 	exp[++k] = '\0';
 	printf("%s\n", exp);

 	return exp;

 }


 int main()
{
    char exp[] = "a+b*c";
    infix_to_prefix(exp);
    return 0;
}