#include "ds.h"

int main() {
	
	struct node *head   = NULL;
	struct node *second = NULL;
	struct node *third  = NULL;
	struct node *one    = NULL;

	one = (struct node*)malloc(sizeof(struct node));
	one->data = 1;
	one->next = NULL;


	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));


	head->data = 2;
	head->next = second;

	second->data = 3;
	second->next = third;

	third->data = 5;
	third->next = NULL;

	printList(head);
	
	push(&head, 1);
	printList(head);

	insert_After(	second, 4);
	printList(head);

	append(&head, 6);
	printList(head);

	struct node * empty = NULL;

	append(&empty, 4);
	printList(empty);

	deleteNode_by_key(&head, 3);
	printList(head);


	deleteNode_by_key(&empty, 4);
	printList(empty);

	deleteNode_by_key(&empty, 4);
	printf("hello\n");
	printList(head);

	deleteNode_by_Pos(&empty, 8);
	printList(head);


	printf("Count = %d\n", getCount(head));

	printf("Count = %d\n", getCountR(head));


	swap(&empty, 2, 4);
	swap(&head, 1, 4);
	printList(head);

	reverse(&head);

	printList(head);




	return 0;
}