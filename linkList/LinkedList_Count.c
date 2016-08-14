#include "ds.h"


/*getCount: returns the length of the LinkedList*/
int getCount(struct node * head) {

	int count = 0;

	while(head != NULL)
	{
		head = head->next;
		count++;
	}

	return count;
}

/*getCountR: returns the length of the LinkedList by calculating it recursively*/
int getCountR(struct node *head) {

	if(head == NULL)
		return 0;

	return 1 + getCountR(head->next);
}