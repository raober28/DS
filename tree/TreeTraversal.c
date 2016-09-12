#include "binaryTree.h"


/*printPostorder: Given a binary treee, print its nodes according to the 
				  "bottom-up* postorder traversa*/
void printPostorder(struct Node *node)
{
	if(node == NULL)
		return;

	//first recur on left subtree
	printPostorder(node->left);

	//then recur on right subtree
	printPostorder(node->right);


	//now deal with the node
	printf("%d ", node->data);
}


/*printInOrder: Given a binary tree, print its nodes in inorder*/
void printInorder(struct Node *node)
{
	if(node == NULL)
		return;

	//first recur on left subtree
	printInorder(node->left);

	//then print the data of node
	printf("%d ", node->data);


	//now recur on right subtree
	printInorder(node->right);
}



/*printPreOrder: Given a binary tree, print its nodes in preorder*/
void printPreorder(struct Node *node)
{
	if(node == NULL)
		return;

	//first print the data of node
	printf("%d ", node->data);
	
	//then recur on left subtree
	printPreorder(node->left);
	
	//now recur on right subtree
	printInorder(node->right);

}
