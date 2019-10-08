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

extern void initQueue(Queue*);
extern int isEmptyQ(Queue queue);
extern void enqueue(Queue*, Qnode);
extern Qnode* delqueue(Queue*);
extern void printQueue(Queue queue);

#endif