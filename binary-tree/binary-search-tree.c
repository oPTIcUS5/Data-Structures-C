#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;

node *new_node(int data);
node *insert(node *root, int value);
node *search(node *root, int objective);
void inorder();
void postororder();
void preorder();

node *new_node(int value)
{
    node *n = (node*)malloc(sizeof(node));
    n->data = value;
    n->left = n->right = NULL;
    
    return n;
}

node *insert(node *root, int value)
{
    if (root == NULL)
        return new_node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    
    return root;
}

node *search(node *root, int objective)
{
    if (root == NULL || root->data == objective)
        return root;
    else if (objective < root->data)
        return search(root->left, objective);
    else
        return search(root->right, objective);
}
