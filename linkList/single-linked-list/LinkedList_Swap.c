#include"ds.h"

/*swap: interchange nodes in the list for the given values*/
void swap(struct node ** head_ref, int x, int y) {

	struct node * curr_node = *head_ref;

	if(curr_node == NULL)
	{
		printf("error: empty list\n");
		return;
	}

	if(x == y)
	{
		printf("warning: swapping same values \n");
		return;
	}


	struct node *prevX = NULL, *currX = *head_ref;

	while(currX && currX->data != x)
	{
		prevX = currX;
		currX = currX->next;
	}


	struct node *prevY = NULL, *currY = *head_ref;
	while(currY && currY->data != y)
	{
		prevY = currY;
		currY = currY->next;
	}

	/*input values are not in the list*/
	if(currX == NULL || currY == NULL)
		return;


	if(prevX != NULL)
		prevX->next = currY;
	else
		*head_ref = currY;		//node is the head element

	if(prevY != NULL)
		prevY->next = currX;
	else
		*head_ref = currX;		//node is the head element


	struct node *temp = currY->next;
	currY->next = currX->next;
	currX->next = temp;
}