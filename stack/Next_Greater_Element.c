#include<stdio.h>
#include<limits.h>
#include "stack.h"


void nge(int *arr, int len)
{
	int i, j, next;

	for(i = 0; i < len; i++)
	{
		next = -1;

		for(j=i+1; j < len; j++)
		{
			if(arr[i] < arr[j])
			{
				next = arr[j];
				break;
			}
		}

		printf("%2d ----> %2d\n", arr[i],next);
	}
}

void nge_stack(int *arr, int len)
{
	struct Stack *stack = createStack(len);
	if(!stack)
		NULL;

	int i, next, top;

	/*push the first element to stack*/
	push(stack, arr[0]);

	/*iterate for rest of the elements*/
	for(i = 1; i < len; i++)
	{
		next = arr[i];

		if(!isEmpty(stack))
		{
			/*if stack is not empty, then pop an element from stack*/
			top = pop(stack);
			
			while(next > top)
			{
				printf("%2d ----> %2d\n", top, next);
				if(isEmpty(stack))
					break;
				top = pop(stack);
			}			

			if(top > next)
				push(stack, top);
		}

		push(stack, next);
	}
		
	while(!isEmpty(stack))
	{
		top = pop(stack);
		next = -1;
		printf("%2d ----> %2d\n", top, next);

	}
	
}

int main(int argc, char const *argv[])
{
	
	int arr[]  = {1};
	int arr1[] = {1, 4};
	int arr2[] = {5, 4, 2, 3, 89, 92};

	nge_stack(arr2, 6);
 
	return 0;
}