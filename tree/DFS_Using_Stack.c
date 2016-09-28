#include "stack_of_treeNodes.h"

void preOrder(struct Node *root)
{
	if(root == NULL)
		return;
	
	Stack *stack = createStack(500);

	while(root)
	{
		printf("%d ", root->data);
		
		if(root->right)
			push(stack, root->right);
		
		if(root->left)
			push(stack, root->left);

		root = pop(stack);
	}


}

/*InOrder: Iterative function to inorder tree traversal*/
void InOrder(struct Node *root)
{
	if(root == NULL)
		return;

	//set current to root of binary tree
	struct Node *current = root;
	Stack *stack = createStack(100);	//Initialize stack
	int done = 0;

	while(!done)
	{	
		//reach the left most node of the current node
		if(current != NULL)
		{
			/*push the curren node on to stack before travesing its left node*/
			push(stack, current);
			current = current->left;
		}
		/*backtrack the tree, by poping nodes from stack */
		else
		{
			if(!isEmpty(stack))
			{
				current = pop(stack);
				printf("%d ", current->data);

				current = current->right;
			}
			else
				done = 1;
		}
	}
	printf("\n");
}


/*postOrder: Iterative function to postOrder traverse the tree*/
void postOrder(struct Node *root)
{
	if(root == NULL)
		return;

	Stack *stack = createStack(100);
	struct Node *current = root;

	do
	{
		while(root)
		{
			if(root->right)
				push(stack, root->right);
			push(stack, root);

			root = root->left;
		}

		root = pop(stack);

		if(root->right && peek(stack) == root->right)
		{
			pop(stack);
			push(stack, root);
			root = root->right;
		}
		else
		{
			printf("%d ", root->data);
			root = NULL;
		}

	} while (!isEmpty(stack));

	printf("\n");
}


int main(int argc, char const *argv[])
{
	struct Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	postOrder(root);
	return 0;
}