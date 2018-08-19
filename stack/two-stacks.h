#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/*two_stack:  represent two stacks with common space */
struct two_stack {
	int capacity;
	int top1;
	int top2;
	int *array;
};

struct two_stack *create_stack(int capacity);

int push1(struct two_stack *stack, int n);
int push2(struct two_stack *stack, int n);

void peek1(struct two_stack *stack);
void peek2(struct two_stack *stack);

int pop1(struct two_stack *stack);
int pop2(struct two_stack *stack);

