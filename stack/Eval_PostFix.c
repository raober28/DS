#include "stack.h"


int isNumber(char ch)
{
	return (ch >= '0'  && ch <= '9');
}


int isOperator(char ch)
{
	return (ch == '+'  || ch == '-' || ch == '*'  || ch == '/');	
}

/*eval_postfix: evaluates a postfix expression
				expr: expects a  valid postfix expression*/
int eval_postfix(char *expr)
{
	int i = 0, a, b, res;

	struct Stack *stack = createStack(strlen(expr));

	if(!stack)
		return NULL;


	/*iterate through the expression*/
	while(expr[i])
	{
		if(isNumber(expr[i]))
		{
			push(stack, expr[i] - '0');
		}

		else if(isOperator(expr[i]))
		{
			if(expr[i] ==  '+')
			{
				a = pop(stack);
				b = pop(stack);

				push(stack, a + b);
			}

			else if(expr[i] ==  '*')
			{
				a = pop(stack);
				b = pop(stack);

				push(stack, a * b);
			}

			else if(expr[i] ==  '-')
			{
				a = pop(stack);
				b = pop(stack);

				push(stack, b - a);
			}

			else if(expr[i] ==  '/')
			{
				a = pop(stack);
				b = pop(stack);

				push(stack, b / a);
			}

			else if(expr[i] ==  '^')
			{
				a = pop(stack);
				b = pop(stack);

				push(stack, b ^ a);
			}

		}

		else 
		{
			printf("error: invalid expression\n");
			return NULL;
		}

		i++;

	}

	res = pop(stack);
	printf("PostFix Expression Evaluation Result = %d\n", res);

	return res;
}



int main(int argc, char const *argv[])
{
	eval_postfix("231*+9-");
	return 0;
}