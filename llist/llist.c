#include "llist.h"


void initList(List* list) {
	list->head = NULL;
	list->tail = NULL;
}
void insertListNode(List* list, ListNode newNode) {
	if (list->head == NULL) {
		list->head = (ListNode*)calloc(1, sizeof(ListNode));
		list->head->data = newNode.data;
		list->head->next = NULL;
		list->tail = list->head;
	}
	else {
		list->tail->next = (ListNode*)calloc(1, sizeof(ListNode));
		list->tail = list->tail->next;
		list->tail->data = newNode.data;
		list->tail->next = NULL;
	}
}
ListNode* searchNode(List list, ListNode node) {
	ListNode* curNode = list.head;
	while (curNode != NULL) {
		if (curNode->data == node.data) {
			return curNode;
		}
		curNode = curNode->next;
	}
	return NULL;
}
void printList(List list) {
	ListNode* curNode = list.head;
	while(curNode != NULL){
		printf("%d", curNode->data);
		curNode = curNode->next;
	}
}