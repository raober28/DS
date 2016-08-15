#include"ds.h"


/*reverse: reverse the whole Linked List*/
void reverse(struct node **head_ref)
{
	struct node *curr_node, *prev_node, *next_node, *temp;

	curr_node = *head_ref;

	/*empty list*/
	if(curr_node == NULL)
		return;

	/*list with only one node*/
	if(curr_node->next == NULL)
		return;


	temp = curr_node;
	
	prev_node = curr_node;
	curr_node = curr_node->next;

	temp->next = NULL;	//making first node last


	while(curr_node != NULL)
	{
		temp = curr_node;
		curr_node = curr_node->next;


		temp->next = prev_node;		//making previous node next to the current node 
		prev_node = temp;
	}

	*head_ref = temp;
}





/* reverse_in_group: Reverses the linked list in groups of size k and returns the 
   	    			 pointer to the new head node. */
struct node *reverse_in_group (struct node *head, int k)
{
    struct node* current = head;
    struct node* next = NULL;
    struct node* prev = NULL;
    int count = 0;   
     
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
     
    /* next is now a pointer to (k+1)th node 
       Recursively call for the list starting from current.
       And make rest of the list as next of first node */
    if (next !=  NULL)
       head->next = reverse_in_group(next, k); 
 
    /* prev is new head of the input list */
    return prev;
}
