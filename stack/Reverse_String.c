#include "stack_char.h"

void reverse(char *str)
{
	int len = strlen(str), i;
	struct Stack *stack = createStack(len);
	char ch, *rev = "";	

	for(i = 0; i < len; i++)
		push(stack, str[i]);
	

	for(i = 0; i < len; i++)
		str[i] = pop(stack);
	
}


