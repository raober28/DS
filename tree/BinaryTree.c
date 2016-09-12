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