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

extern void InitMinHeap(MinHeap* heap, int maxSize);
extern void SiftdownMinHeap(MinHeap* heap, int root);
extern MinHeapNode DeleteMinHeap(MinHeap* heap);
extern void InsertMinHeap(MinHeap* heap, MinHeapNode new);
extern void PrintMinHeap(MinHeap heap);
#endif