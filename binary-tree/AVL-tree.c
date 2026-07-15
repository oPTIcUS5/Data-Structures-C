#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *left;
    int data;
    struct Node *right;

    int height;
}Node;

/* Create node function */
Node *createNode(int value) {

    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->data = value;
    newNode->left = newNode->right = NULL;

    newNode->height = -1;

    return newNode;
}

/* Auxiliar functions: */
/* */

