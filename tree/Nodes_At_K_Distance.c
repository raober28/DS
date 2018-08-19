#include "binaryTree.h"


/*printKDistantNodes: Given a root of a tree, and an integer k.
					  Print all the nodes which are at k distance from root.*/
void printKDistantNodes(struct Node *node, int k)
{
	if(node == NULL)
		return;

	// this node is k distance from the inital root node
	if(k == 0)
	{
		printf("%d ", node->data);
		return;
	}
	//iterate throught the tree recursively with reducing k by 1
	else
	{
		printKDistantNodes(node->left,  k -1);
		printKDistantNodes(node->right, k -1);
	}

}


int main(int argc, char const *argv[])
{
  struct Node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(8); 

  printKDistantNodes(root, 2);
  printf("\n");

	return 0;
}