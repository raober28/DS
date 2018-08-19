#include "stack_char.h"


int is_balanced_parantheses(char *expr)
{
	int len =  strlen(expr);

	struct Stack *stack = createStack(len);

	while(*expr)
	{
		if(*expr ==  '{' || *expr ==  '(' || *expr ==  '[')
			push(stack, *expr);

		else if(*expr == '}')
		{
			if(pop(stack)  != '{')	//no matching starting curly brace found
				return 0;
		}
		
		else if(*expr == ')')
		{
			if(pop(stack)  != '(')	//no matching starting brace found
				return 0;
		}
		else if(*expr == ']')
		{
			if(pop(stack)  != '[')	//no matching starting bracket found
				return 0;
		}

		expr++;
		
	}

	if(isEmpty(stack))
	{
		free(stack);
		return 1;
	}

	free(stack);
	return 0;
}