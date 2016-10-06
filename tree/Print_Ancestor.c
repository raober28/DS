#include "binaryTree.h"
#define true 1
#define false 0

/*print_ancestor: if target is present in tree, then prints the ancestors
				  and returns true, otherwise returns false */
int print_ancestor(struct Node *root, int target)
{
	if(root == NULL)
		return false;

	if(root->data == target)
		return true;

	/*if target is present in either left or right subtree of this node,
	  then print this node*/
	if(print_ancestor(root->left, target) || print_ancestor(root->right, target))
	{
		printf("%d ", root->data);
		return true;
	}

	return false;

}

int main(int argc, char const *argv[])
{
  struct Node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->left->left->left = newNode(7); 

  print_ancestor(root, 7);
  printf("\n");

	return 0;
}