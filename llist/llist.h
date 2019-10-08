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

extern void initList(List* list);
extern void insertListNode(List*, ListNode);
extern ListNode* searchNode(List, ListNode);
extern void deleteNode(Node);
extern void printList(List list);
#endif