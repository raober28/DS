#include "treeTraversal.h"


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

/*height: Compute the height of a tree --the number of nodes along the longest path
		  from the root node down to the farthest leaf node*/
int height(struct Node *root)
{
	if(root == NULL)
		return 0;
	else 
	{
		int lheight = height(root->left);
		int rheight = height(root->right);

		if(lheight > rheight)
			return(lheight + 1);
		else 
			return (rheight + 1);
	}
}

/*printGivenLevel: Prints all the nodes at a given level in a tree*/
void printGivenLevel(struct Node *root, int level)
{
	if(root == NULL)
		return;
	
	else if(level == 1)
		printf("%d ", root->data);
	
	else if(level > 1)
	{
		printGivenLevel(root->left, level - 1);
		printGivenLevel(root->right, level -1);
	}

}

/*printLevelorder: Function to print all the nodes at all levels in tree in sequential order*/
void printLevelorder(struct Node *root)
{
	int i, h;

	h = height(root);

	for(i = 1;i <= h; i++)
		printGivenLevel(root, i);
}


