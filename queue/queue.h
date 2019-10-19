#ifndef _Q_H_
#define _Q_H_
#include <stdio.h>
#include <stdlib.h>


typedef int Data;

typedef struct _qnode {
	Data data;
	struct _qnode* next;
}Qnode;
typedef struct _q {
	struct _qnode* front;
	struct _qnode* rear;
}Queue;

extern void InitQueue(Queue* queue);
extern int IsEmptyQ(Queue queue);
extern void Enqueue(Queue* queue, Data data);
extern Data Delqueue(Queue* queue);
extern void PrintQueue(Queue queue);

#endif