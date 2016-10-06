#include "binaryTree.h"
#define true 1
#define false 0


/*areIdentical: a utility function that checks, whether trees with root as root1 and root2 
			    are identical or not*/
int areIdentical(struct Node *root1, struct Node *root2)
{
	if(root1 == NULL && root2 == NULL)
		return true;

	if(root1 == NULL || root2 == NULL)
		return false;

	//checks if the data of both roots are same and data of left and right subtree are also same
	return (root1->data == root2->data && 
			areIdentical(root1->left, root2->left) && 
			areIdentical(root1->right, root2->right));
}


/*isSubtree: returns true if s is subtree of t*/
int isSubtree(struct Node *t, struct Node *s)
{	
	if(s == NULL)
		return true;

	if(t == NULL)
		return false;


	if(areIdentical(t, s))
		return true;

	/*If the tree with root as current node does not match then
	  try left and right subtrees one by one*/
	return isSubtree(t->left, s) || isSubtree(t->right, s);

}


int main()
{
    // TREE 1
    /* Construct the following tree
              26
            /   \
          10     3
        /    \     \
      4      6      3
       \
        30
    */
    struct Node *T        = newNode(26);
    T->right              = newNode(3);
    T->right->right       = newNode(3);
    T->left               = newNode(10);
    T->left->left         = newNode(4);
    T->left->left->right  = newNode(30);
    T->left->right        = newNode(6);
 
    // TREE 2
    /* Construct the following tree
          10
        /    \
      4      6
       \
        30
    */
    struct Node *S    = newNode(10);
    S->right          = newNode(6);
    S->left           = newNode(4);
    S->left->right    = newNode(30);
 
 
    if (isSubtree(T, S))
        printf("Tree 2 is subtree of Tree 1");
    else
        printf("Tree 2 is not a subtree of Tree 1");
 
    return 0;
}