#include "binaryTree.h"
#define true 1
#define false 0


/*printInt: prints all item of array*/
void printInt(int *arr)
{
  int  i = 0;
  while(arr[i])
  {
    printf("%d ", arr[i]);
    i++;
  }

  printf("\n");
}

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

/*

             26
            /   \
          10     3
        /    \     \
      4      6      3
       \
        30*/

void find_InOrder(struct Node *t, int *arr)
{
  static int i = 0;
  if(t == NULL)
  { 
    arr  =  NULL;
    return;
  }
  
  find_InOrder(t->left,  arr);
  *(arr + i) = t->data;
  i++;
  find_InOrder(t->right, arr);
}

void find_preOrder(struct Node *t, int *arr)
{
  static int i = 0;
  if(t == NULL)
  {
    arr = NULL;
    return;
  }

  *arr = t->data;
  arr++;
  find_preOrder(t->left, arr);
  
  find_preOrder(t->right, arr);
}

/*isSubtree: check if the gicen tree s is sutree of tree t or not*/
/*int isSubArray(int *s, int *t, int s_len, int t_len)
{
  //iterate the tree t
  for(int i = 0, j = 0; i < t_len - s_len - 1; i++)
  {
    j = 0;

    while(*(t[i]) == *(s[j]))
      j++;
    
    //if whole tree s has matched with tree t that means s is a subtree of tree t
    if(j == s_len)
      return true;
  }

  return false;
}*/

int isSubtree_Optimised(struct Node *t, struct Node *s)
{
  int *t_in;
  //, t_pre[100], s_in[100], s_pre[100];

  find_InOrder(t , t_in);
  printInt(t_in);

  /*find_preOrder(t, t_pre);
  printInt(t_pre, 100);
  
  find_InOrder(s , s_in);
  printInt(s_in, 100);

  find_preOrder(s, s_pre);
  printInt(s_pre, 100);*/
/*
  int t_len = size_of(t_in)/size_of(t_in[0]);
  int s_len = size_of(s_in)/size_of(s_in[0]);

  if(isSubArray(s_in, s_len, t_in, t_len) && isSubArray(s_pre, s_len, t_pre, t_len));
    return true;*/

  return false;
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
 
 
    if (isSubtree_Optimised(T, S))
        printf("Tree 2 is subtree of Tree 1\n");
    else
        printf("Tree 2 is not a subtree of Tree 1\n");

    return 0;
}