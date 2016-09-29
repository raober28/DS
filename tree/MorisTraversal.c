#include "binaryTree.h"


/*morrisTraversal: traverse the tree inorder, wihout using recursion and without stack */
void morrisTraversal(struct Node *root)
{

  if(root == NULL)
    return;

  struct Node *current, *pre;

  current = root;
  while(current)
  {
    if(current->left  == NULL)
    {
      printf("%d ", current->data);
      current = current->right;
    }
    else
    {
      //Find the inorder predecessor of current, find the rightmost element in the left subtree
      pre = current->left;

      while(pre->right && pre->right != current)
        pre = pre->right;

      //Make current as right child of its inorder predecessor
      if(pre->right == NULL)
      {
        pre->right = current;
        current = current->left;
      }

      /*Revert the changes made in if part to restore the original
        tree i.e fix the right child of predecssor*/
      else
      {
        pre->right = NULL;
        printf("%d ",current->data);
        current = current->right;
      }
    }
  }
}
