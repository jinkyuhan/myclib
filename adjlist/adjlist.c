#include "adjlist.h"
#define TRUE 1
#define FALSE 0

int initAdjList(AdjList *adjlist, int numOfVertex) {
  adjlist->numOfVertex = numOfVertex;
  adjlist->numOfEdge = 0;
  if (((adjlist->head = (Node **)malloc(sizeof(Node *) * (numOfVertex + 1))) ==
       NULL) ||
      ((adjlist->tail = (Node **)malloc(sizeof(Node *) * (numOfVertex + 1))) ==
       NULL))
    return FALSE;
  return TRUE;
}
void insertDirectedEdge(AdjList *adjlist, Edge edge) {
  if (adjlist->head[edge.fromVertex] == NULL) {
    adjlist->head[edge.fromVertex] = (Node *)malloc(sizeof(Node));
    adjlist->head[edge.fromVertex]->toVertex = edge.toVertex;
    adjlist->head[edge.fromVertex]->weight = edge.weight;
    adjlist->head[edge.fromVertex]->next = NULL;
    adjlist->tail[edge.fromVertex] = adjlist->head[edge.fromVertex];
  } else {
    adjlist->tail[edge.fromVertex]->next = (Node *)malloc(sizeof(Node));
    adjlist->tail[edge.fromVertex] = adjlist->tail[edge.fromVertex]->next;
    adjlist->tail[edge.fromVertex]->toVertex = edge.toVertex;
    adjlist->tail[edge.fromVertex]->weight = edge.weight;
    adjlist->tail[edge.fromVertex]->next = NULL;
  }
  adjlist->numOfEdge++;
}
void insertUnDirectedEdge(AdjList *adjlist, Edge edge) {
  Edge reverseEdge = (Edge){edge.toVertex, edge.fromVertex, edge.weight};
  insertDirectedEdge(adjlist, edge);
  insertDirectedEdge(adjlist, reverseEdge);
  adjlist->numOfEdge--;
}

void deleteDirectedEdge(AdjList *adjlist, Edge edge) {
  Node *delete;
  Node *parent;
  Node *curNode;
  parent = adjlist->head[edge.fromVertex];
  curNode = parent->next;
  if ((parent->toVertex == edge.toVertex) && (parent->weight == edge.weight)) {
    if (parent != adjlist->tail[edge.fromVertex]) {
      free(adjlist->head[edge.fromVertex]);
      adjlist->head[edge.fromVertex] = curNode;
    }
    else{
      free(adjlist->head[edge.fromVertex]);
      adjlist->head[edge.fromVertex] = NULL;
    }
    adjlist->numOfEdge--;
  }
  else{
    while(curNode != NULL){
      if((curNode->toVertex == edge.toVertex) && (curNode->weight == edge.weight)){
        if(curNode == adjlist->tail[edge.fromVertex]){
          adjlist->tail[edge.fromVertex] = parent;
        }
        parent->next = curNode->next;
        free(curNode);
        adjlist->numOfEdge--;
        break;
      }
      parent = parent->next;
      curNode = curNode->next;
    }
  }
}
void deleteUnDirectedEdge(AdjList *adjlist, Edge edge){
  Edge reverseEdge = (Edge){edge.toVertex, edge.fromVertex, edge.weight};
  deleteDirectedEdge(adjlist, edge);
  deleteDirectedEdge(adjlist, reverseEdge);
  adjlist->numOfEdge++;
}
Node *searchNode(AdjList adjlist, Edge edge) {
  Node *curNode = adjlist.head[edge.fromVertex];
  while (curNode != NULL) {
    if ((curNode->toVertex == edge.toVertex) && (curNode->weight)) {
      return curNode;
    }
    curNode = curNode->next;
  }
  return NULL;
}
void fprintAllEdges(AdjList adjlist, FILE *f) {
  int i;
  Node *curNode;
  for (i = 1; i <= adjlist.numOfVertex; i++) {
    curNode = adjlist.head[i];
    while (curNode != NULL) {
      fprintf(f, "(%d, %d, weight:%d)\n", i, curNode->toVertex,
              curNode->weight);
      curNode = curNode->next;
    }
  }
}
void freeAlledge(Node *fromVertexHead) {
  if (fromVertexHead == NULL)
    ;
  else {
    freeAlledge(fromVertexHead->next);
    free(fromVertexHead);
    fromVertexHead = NULL;
  }
}
void freeAdjList(AdjList *adjlist, int numOfVertex) {  // test필요
  int i;
  Node **curHead = adjlist->head;
  for (i = 1; i <= numOfVertex; i++) {
    freeAlledge(curHead[i]);
  }
}