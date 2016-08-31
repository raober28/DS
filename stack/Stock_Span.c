#include "stack.h"
#include "util.h"

int cal_span(struct Stack *stack, int item)
{
	if(isEmpty(stack) || item < peek(stack))
		return 1;
	else
	{
		int temp = pop(stack);
		int result = 1 + cal_span(stack, item); 
		
		push(stack, temp);
		return result;
	}
}


int span(struct Stack *stack)
{
	if(!isEmpty(stack))
	{
		int item = pop(stack);
		int result = cal_span(stack, item);
		
		printf("%3d---->%3d\n", item, result);

		span(stack);

		push(stack, item);
	}	
	
}

void calculateSpan(int price[], int n, int s[])
{	
	/*create a stack and push index of first elemen to it*/
	struct Stack *stack = createStack(n);
	push(stack, 0);

	/*span values of first element will always be 1*/
	s[0] = 1;

	/*calculating span values for rest of elements*/
	for(int i = 1; i < n; i++)
	{
		/*Pop elements from stack while stack is not empty and
		  top of stack is smaller than price[i]*/
		while(!isEmpty(stack) && price[peek(stack)] <= price[i])
			pop(stack);


		/*If stack becomes empty, then price[i] is greater than all elements
		  on left of it. Else price[i] is greater than elements after top of stack*/
		s[i] = (isEmpty(stack))? (i + 1): (i - peek(stack));

		/*push this element to stack*/
		push(stack, i);

	}
}


int main(int argc, char const *argv[])
{
	int price[] = {10, 4, 5, 90, 120, 80};
    int n = sizeof(price)/sizeof(price[0]);
    int S[n];
 	
 	printArray(price, n);
    // Fill the span values in array S[]
    calculateSpan(price, n, S);
 
    // print the calculated span values
 	   printArray(S, n);
 
    return 0;

}