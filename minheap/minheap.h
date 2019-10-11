#ifndef _MINHEAP_H_
#define _MINHEAP_H_
#include <stdio.h>
#include <stdlib.h>

typedef int Data;
typedef struct _minheapnode {
	int key;
	Data data;
}MinHeapNode;

typedef struct _heap {
	struct _minheapnode* heapTree;
	int heapSize;
}MinHeap;

extern void initMinHeap(MinHeap* heap, int maxSize);
extern void siftdownMinHeap(MinHeap* heap, int root);
extern MinHeapNode deleteMinHeap(MinHeap* heap);
extern void insertMinHeap(MinHeap* heap, MinHeapNode new);
extern void printMinHeap(MinHeap heap);
#endif