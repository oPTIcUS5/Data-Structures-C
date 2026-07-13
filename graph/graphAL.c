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

/* add edge function */
void addEdge(Graph *grap, int origin, int destiny);

/* Display function*/
void display(Graph *graph);

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

// addEdge function
void addEdge(Graph *graph, int origin, int destiny) {

    Node *newNode = createNode(destiny);

    newNode->nextNode = graph->list[origin];
    graph->list[origin] = newNode;

    newNode = createNode(origin);

    newNode->nextNode = graph->list[destiny];
    graph->list[destiny] = newNode;
}

// display fucntion
void display(Graph *graph) {

    for (int i = 0; i < graph->vertices; i++) {

        printf("[%d]: --> ", i);
        
        Node *auxiliar = graph->list[i];

        while (auxiliar != NULL) {
            
            printf("%d --> ", auxiliar->destiny);
            auxiliar = auxiliar->nextNode;
        }
        printf("NULL\n");
    }
}
