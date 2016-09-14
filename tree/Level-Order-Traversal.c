#include "queue_of_treeNodes.h"

void printLevelOrder(TNode *root)
{
	Queue *queue = createQueue(N);
	TNode  *node  = root;

	while(node)
	{
		printf("%d ", node->data);

		if(node->left)
			enqueue(queue, node->left);
		if(node->right)
			enqueue(queue, node->right);

		node = dequeue(queue);
	}

	printf("\n");
}

int main(int argc, char const *argv[])
{
	TNode *root       = createTreeNode(1);
	root->left        = createTreeNode(2);
	root->right       = createTreeNode(3);
	root->left->left  = createTreeNode(4);
	root->left->right = createTreeNode(5);

	printLevelOrder(root);
	return 0;
}

