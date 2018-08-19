#include "tree_diameter.h"

/*diameter: calculates the diameter of the given tree
            The diameter of a tree (sometimes called the width) is the number of nodes 
            on the longest path between two leaves in the tree. */
int diameter(struct Node *tree)
{
	/*when tree is empty diameter is 0*/
	if(tree == NULL)
		return 0;

	int lheight = height(tree->left);
	int rheight = height(tree->right);

	//get the diameter of left and right sub-tree
	int ldiameter = diameter(tree->left);
	int rdiameter = diameter(tree->right);

	/*Return max of following three
	  1) Diameter of left  subtree
	  2) Diameter of right subtree
	  3) Height of left subtree + height of right subtree + 1*/
	return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}

/*diameterOpt: Optimised version of above diameter function*/
int diameterOpt(struct Node *root, int *height)
{	
	/*lh -> height of left   subtree
      rh -> height of rigfht subtree*/
	int lh = 0, rh = 0;

	/*ldiameter -> diameter of left subtree
	  rdiameter -> diameter of right subtree*/
	int ldiameter = 0, rdiameter = 0;

	if(root == NULL)
	{
		*height = 0;
		return 0;	//diameter of empty tree is 0
	}

	/*Get the height of left and right subtrees in lh and rh
	  And store the returnd values in ldiameter and rdiameter	*/
	ldiameter = diameterOpt(root->left, &lh);
	rdiameter = diameterOpt(root->right, &rh);

	/*Height of current node is max of heights of left and right subtrees plus 1 */
	*height = max(lh, rh) + 1;

	return max(lh + rh + 1, max(ldiameter, rdiameter));
}