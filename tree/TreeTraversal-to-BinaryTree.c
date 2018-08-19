#include "treeTraversal.h"


/*getInOrderIndex: search the given data in inOrder array and return its index*/
int getInOrderIndex(int inOrder[], int start, int end, int data)
{
	int i;

	for(i = start; i <= end; i++)
	{
		if(inOrder[i] == data)
			return i;
	}
	return -1;
}

/*makeBinaryTree: create a Binary Tree using inOrder and preOrder traversal*/
struct Node *makeBinaryTree(int inOrder[], int  preOrder[], int start, int end)
{
	static int preIndex = 0;
	if(start > end)
		return NULL;

	struct Node *root = newNode(preOrder[preIndex++]);

	if(start == end)
		return root;

	int index   = getInOrderIndex(inOrder, start, end, root->data);
	root->left  = makeBinaryTree(inOrder, preOrder, start, index - 1);
	root->right = makeBinaryTree(inOrder, preOrder, index + 1, end);

	return root;
}


int main(int argc, char const *argv[])
{
	int inOrder[]  = {2, 5, 6, 10, 12, 14, 15};	//InOrder traversal of a Binary Tree
	int preOrder[] = {10, 5, 2, 6, 14, 12, 15};	//PreOrder traversal of a Binary Tree

	int length = sizeof(inOrder) / sizeof(inOrder[0]);
	struct Node *root = makeBinaryTree(inOrder, preOrder, 0, length - 1);
	printf("%s\n", "Constructed Tree");
	
	printInorder(root);	
	printf("\n");
	printPreorder(root);
	printf("\n");
	return 0;
}