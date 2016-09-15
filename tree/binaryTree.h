#include <stdio.h>
#include <stdlib.h>
#include "util.h"

/*A binary tree node that has atmost two childs */
struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};


struct Node *newNode(int n);

int height(struct Node *node);

