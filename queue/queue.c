#include "queue.h"
#define TRUE 1
#define FALSE 0

void InitQueue(Queue* queue) {
	queue->rear = (Qnode*)calloc(1, sizeof(Qnode));
	queue->front = queue->rear;
}
int IsEmptyQ(Queue queue) {
	if (queue.front == queue.rear) {
		return TRUE;
	}
	return FALSE;
}
void Enqueue(Queue* queue, Data data) {
	queue->rear->data = data;
	queue->rear->next = (Qnode*)calloc(1, sizeof(Qnode));
	queue->rear = queue->rear->next;
	queue->rear->next = NULL;
}
Data Delqueue(Queue* queue) {
	Data del;
	Qnode* delNode;
	delNode = queue->front;
	queue->front = queue->front->next;
	del = delNode->data;
	free(delNode);
	return del;
}
void PrintQueue(Queue queue) {
	Qnode* curNode = queue.front->next;
	while (curNode != NULL) {
		printf("%d ", curNode->data);
		curNode = curNode->next;
	}
}
