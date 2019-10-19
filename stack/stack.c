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

Data PopStack(Stack* stack) {
	StackNode* popNode;
	Data popData;
	if (!IsEmptyStack(*stack)) {
		popNode = stack->top;
		stack->top = stack->top->prev;
		popData = popNode->data;
		free(popNode);
		return popData;
	}
	return NULL;
}
