#ifndef _ADJLIST_H
#define _ADJLIST_H
#include <stdio.h>
#include <stdlib.h>
//------------------------------------------------------
//  The linked-list structure as representation of a Graph
//   #example
//      graph has {
//              edge(1, 2, weight(1)),
//              edge(1, 4, weight(2)),
//              edge(2, 3, weight(3)),
//              edge(3, 1, weight(4)),
//              edge(4, 1, weight(5))
//                }
//
//   head[1]  -> Node{2, 1(weight), linkToNext} -> Node{4, 2(weight), NULL} <- tail[1]
//   head[2]  -> Node{3, 3(weight), linkToNext} <- tail[2]
//   head[3]  -> Node{1, 4(weight), linkToNext} <- tail[3]
//   head[4]  -> Node{1, 5(weight), linkToNExt} <- tail[4]
//------------------------------------------------------

typedef struct _node{
    int toVertex;
    int weight;
    struct _node* next;
}Node;
typedef struct _edge{
    int fromVertex;
    int toVertex;
    int weight;
}Edge;

typedef struct _adjlist{
    struct _node** head;
    struct _node** tail;
    int numOfVertex;
    int numOfEdge;
}AdjList;

extern int initAdjList(AdjList* adjlist, int numOfVertex);
/* This function initialize the adjlist. it makes the head[] and tail[] arrays numOfVertex length.
Each index of these array is the identification of each vertex.
1 is returned on Sucess
0 is returned on fail*/
extern void insertDirectedEdge(AdjList* adjlist, Edge edge);
/* This function inserts The edge which has direction to adjList. */

extern void insertUnDirectedEdge(AdjList* adjlist, Edge edge);
/* This function inserts The edge which has no direction to adjList. */

extern Node* deleteEdge(AdjList* adjlit, Edge edge);
/* This function*/  

extern Node* searchNode(AdjList adjlist, Edge edge);
/* This function searches and returns a pointer of a node represents the edge in the adjlist.*/

extern void fprintAllEdges(AdjList adjlist, FILE* f);
/* This function prints all the edges in adjlist to file f.
if you want to print these to stdout, you give the 'stdout' argumnet*/
void* getHead();
void* getTail();
void freeAdjList();

#endif