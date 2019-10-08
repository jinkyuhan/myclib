#include "queue.h"
#define TRUE 1
#define FALSE 0

void initQueue(Queue* queue) {
	queue->rear = (Qnode*)calloc(1, sizeof(Qnode));
	queue->front = queue->rear;
}
int isEmptyQ(Queue queue) {
	if (queue.front == queue.rear) {
		return TRUE;
	}
	return FALSE;
}
void enqueue(Queue* queue, Qnode new) {
	queue->rear->next = (Qnode*)calloc(1, sizeof(Qnode));
	queue->rear = queue->rear->next;
	queue->rear->data = new.data;
	queue->rear->next = NULL;
}
Qnode* delqueue(Queue* queue) {
	queue->front = queue->front->next;
	return queue->front;
}
void printQueue(Queue queue) {
	Qnode* curNode = queue.front->next;
	while (curNode != NULL) {
		printf("%d ", curNode->data);
		curNode = curNode->next;
	}
}
