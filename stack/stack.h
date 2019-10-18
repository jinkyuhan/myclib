#ifndef _STACK_H_
#define _STACK_H_
#include <stdio.h>
#include <stdlib.h>

typedef int Data;
typedef struct _stackNode {
	Data data;
	struct _stackNode* prev;
	struct _stackNode* next;
}StackNode;
typedef struct _stack {
	struct _stackNode* top;
}Stack;

extern void InitStack(Stack* stack);
extern int IsEmptyStack(Stack stack);
extern void PushStack(Stack* stack, Data);
extern StackNode* PopStack(Stack* stack);
#endif