#include "llist.h"


void InitList(List* list) {
	list->head = NULL;
	list->tail = NULL;
}
void InsertListNode(List* list, Data data) {
	if (list->head == NULL) {
		list->head = (ListNode*)calloc(1, sizeof(ListNode));
		list->head->data = data;
		list->head->next = NULL;
		list->tail = list->head;
	}
	else {
		list->tail->next = (ListNode*)calloc(1, sizeof(ListNode));
		list->tail = list->tail->next;
		list->tail->data = data;
		list->tail->next = NULL;
	}
}
ListNode* SearchNode(List list, Data data) {
	ListNode* curNode = list.head;
	while (curNode != NULL) {
		if (curNode->data == data) {
			return curNode;
		}
		curNode = curNode->next;
	}
	return NULL;
}
void PrintList(List list) {
	ListNode* curNode = list.head;
	while (curNode != NULL) {
		printf("%d ", curNode->data);
		curNode = curNode->next;
	}
}