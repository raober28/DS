#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct frame {
	int data;
	struct frame *next;
};

struct StackL {
	struct frame *top;	
};

struct StackL* createStack(void);
struct frame* createframe(int n);

int isEmpty(struct StackL *stackl);

void push(struct StackL *stackl, int n);
struct frame *pop(struct StackL * stackl);
struct frame *peek(struct StackL * stackl);


