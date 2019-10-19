#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include <stdio.h>
#include <stdlib.h>
typedef int Data;

typedef struct _listnode {
	Data data;
	struct _listnode* next;
}ListNode;
typedef struct _list {
	struct _listnode* head;
	struct _listnode* tail;
}List;

extern void InitList(List* list);
extern void InsertListNode(List*, Data);
extern ListNode* SearchNode(List, Data);
extern void PrintList(List list);
#endif