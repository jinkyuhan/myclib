#include "minheap.h"
#define TRUE 1
#define FALSE 0

void InitMinHeap(MinHeap* heap, int maxSize) {
	heap->heapTree = (MinHeapNode*)calloc(maxSize, sizeof(MinHeapNode));
	heap->heapSize = 0;
}


void SiftdownMinHeap(MinHeap* heap, int root)
{
	MinHeapNode siftkey = heap->heapTree[root];
	int parent = root;
	int found = FALSE;
	int smallerChild;
	while ((2 * parent <= heap->heapSize) && (!found))
	{
		if ((2 * parent + 1 <= heap->heapSize) && (heap->heapTree[2 * parent].key > heap->heapTree[2 * parent + 1].key))
		{
			smallerChild = 2 * parent + 1;
		}
		else
		{
			smallerChild = 2 * parent;
		}

		if (siftkey.key > heap->heapTree[smallerChild].key)
		{
			heap->heapTree[parent] = heap->heapTree[smallerChild];
			parent = smallerChild;
		}
		else found = TRUE;
	}
	heap->heapTree[parent] = siftkey;
}

MinHeapNode DeleteMinHeap(MinHeap* heap) {
	if (heap->heapSize < 1) {
		fprintf(stderr, "MinHeap is empty But deleteMinHeap called");
		exit(1);
	}
	MinHeapNode keyout = heap->heapTree[1];
	heap->heapTree[1] = heap->heapTree[heap->heapSize];
	heap->heapSize--;
	siftdownMinHeap(heap, 1);
	return keyout;
}

void InsertMinHeap(MinHeap* heap, MinHeapNode new) {
	int child;
	int parent;
	heap->heapSize++;
	child = heap->heapSize;
	parent = child / 2;
	while ((parent >= 1) && (new.key < heap->heapTree[parent].key)) {
		heap->heapTree[child] = heap->heapTree[parent];
		child = parent;
		parent = parent / 2;
	}
	heap->heapTree[child] = new;
}
void PrintMinHeap(MinHeap heap) {
	int i;
	for (i = 1; i <= heap.heapSize; i++)
	{
		printf("(%d %d) ", heap.heapTree[i].key, heap.heapTree[i].data);
	}
	printf("\n");
}