#include "binaryTree.h"


void printLeftView(struct Node *root, int currLevel);


/*printLeftView: Recursive function to print left view of a binary tree.
				 Left view of a Binary Tree is set of nodes visible when tree is visited from left side.
				 Left view of following tree is 12, 10, 25.
		

							 12
					        /  \
					      10    30
					            / \
					          25   40 


				 */
void printLeftView(struct Node *root, int currLevel)
{
	static int maxLevel = 0;
	if(root == NULL)
		return;
	if(currLevel > maxLevel)
	{
		printf("%d ", root->data);
		maxLevel = currLevel;
	}

	printLeftView(root->left,  currLevel + 1);
	printLeftView(root->right, currLevel + 1);
}


int main(int argc, char const *argv[])
{
	struct Node *root = newNode(12);
	root->left  = newNode(10);
	root->right = newNode(30);
	root->left->right  = newNode(35);
	root->right->left = newNode(25);
	root->right->right = newNode(40);
	root->right->right->right = newNode(54);
	
	printLeftView(root, 1);
	printf("\n");
	return 0;
}
     	