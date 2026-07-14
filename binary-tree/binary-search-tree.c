#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define JUMP printf("\n");

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}node;

node *new_node(int data);
node *insert(node *root, int value);
node *search(node *root, int objective);
void inOrder(node *root);
void postOrorder(node *root);
void preOrder(node *root);

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

void preOrder(node *root) {

    if (root == NULL)
        return;
    else {

        printf("%d, ", root->data);

        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(node *root) {
    if (root == NULL)
        return;
    else {

        inOrder(root->left);
        printf("%d, ", root->data);
        inOrder(root->right);
    }
}

void postOrder(node *root) {

    if (root == NULL)
        return;
    else {

        postOrder(root->left);
        postOrder(root->right);
        printf("%d, ", root->data);
    }
}

int main(void) {

    node *bst = new_node(23);
    bst = insert(bst, 25);
    bst = insert(bst, 15);
    bst = insert(bst, 35);

    preOrder(bst);
    JUMP
    inOrder(bst);
    JUMP
    postOrder(bst);
    JUMP

    return 0;
}
