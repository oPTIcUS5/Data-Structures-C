#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int destiny;
    struct Node *nextNode;
}Node;

typedef struct Graph
{
    int vertices;
    Node **list;
}Graph;

/* Create Functions */
Graph *createGraph(int numVertices);
Node *createNode(int destiny);

/* Insert function */

/* Display function*/

/* Delete functions */

// create a graph
Graph *createGraph(int numVertices) {

    Graph *graph = (Graph*)malloc(sizeof(Graph));

    graph->vertices = numVertices;

    graph->list = (Node**)malloc(numVertices * sizeof(Node*));

    for (int i = 0; i < graph->vertices; i++)
        graph->list[i] = NULL;

    return graph;
}

// create a Node
Node *createNode(int destiny) {

    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->destiny = destiny;
    newNode->nextNode = NULL;

    return newNode;
}
