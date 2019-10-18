#include "stack.h"
#define TRUE 1
#define FALSE 0


void InitStack(Stack* stack) {
	stack->top = NULL;
}

int IsEmptyStack(Stack stack) {
	if (stack.top == NULL) {
		return TRUE;
	}
	return FALSE;
}

void PushStack(Stack* stack, Data data) {
	if (IsEmptyStack(*stack)) {
		stack->top = (StackNode*)calloc(1, sizeof(StackNode));
		stack->top->data = data;
		stack->top->prev = NULL;
		stack->top->next = NULL;
	}
	else {
		stack->top->next = (StackNode*)calloc(1, sizeof(StackNode));
		stack->top->next->prev = stack->top;
		stack->top = stack->top->next;
		stack->top->data = data;
		stack->top->next = NULL;
	}
}

StackNode* PopStack(Stack* stack) {
	StackNode* popNode;
	if (!IsEmptyStack(*stack)) {
		popNode = stack->top;
		stack->top = stack->top->prev;
		return popNode;
	}
	return NULL;
}
