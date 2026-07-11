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
