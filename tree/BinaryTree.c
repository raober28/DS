#include "binaryTree.h"

/*newNode: allocates memory for new node and initialize its data*/
struct Node *newNode(int n)
{
	struct Node *node = (struct Node *)malloc(sizeof(struct Node));
	
	node->data = n;

	//Initialize left and right children as NULL
	node->left = NULL;
	node->right = NULL;
	return node;
}


/*height: Compute the height of a tree. Height is the number of nodes along the longest path 
		  from root node down to the farthest leaf node*/
int height(struct Node *root)
{
	if(root == NULL)
		return 0;

	/*If tree is not empty than height = 1 + max of left height and right height*/
	return 1 + max(height(root->left), height(root->right));
}
