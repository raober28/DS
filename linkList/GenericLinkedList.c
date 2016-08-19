#include <stdio.h>
#include <stdlib.h>


/*A generic linked list node*/
struct node
{
    void *data;

    struct node *next;
};



/*push: add a node to the beginning of the linked list.
        expects a pointer to the data to be added
        and the size of the data type*/
void push(struct node **head_ref, void *new_data, size_t data_size)
{
    //Allocate memory for node
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    new_node->next = *head_ref;
    new_node->data = malloc(data_size);


    //Copy contents of new_data to the new allocated memory
    int i = 0;
    for(i = 0; i < data_size; i++)
        *(char *)(new_node->data + i) = *(char *)(new_data + i);

    
    //change head pointer as new node is added at the beginning 
    *head_ref = new_node;

}



/*printList: prints nodes in a given linked list.
             fptr is used to access the function to be used to print the current node*/
void printList(struct node *node, void(* fptr)(void *))
{
    while(node != NULL)
    {
        (*fptr)(node->data);
        node = node->next;
    }

    printf("\n");
}


/*printInt: print an Int value*/
void printInt(void *n)
{
    printf(" %d", *(int *)n);
}

/*printFloat: print an Float value*/
void printFloat(void *n)
{
    printf(" %f", *(float *)n);
}


int main()
{
    struct node *start = NULL;


    unsigned int_size = sizeof(int);
    int arr[] = {10, 20, 30, 40, 50}, i;

    for(i = 4; i >= 0; i--)
        push(&start, &arr[i], int_size);

    printf("Created integer linked list is \n");
    printList(start, printInt);


    unsigned float_size = sizeof(float);

    start = NULL;
    float arr2[] =  {10.1, 20.2, 30.3, 40.4, 50.5};

    for(i = 4; i >=0; i--)
        push(&start, &arr2[i], float_size);

    printf("Created float linked list is \n");
    printList(start, printFloat);

    return 0;


}


