#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left_node;
    struct node *right_node;
}node;

node *create_node(int value);
void insert_beg(node **start, int value);
void insert_end(node **start, int value);
void del_end(node **start);
void del_beg(node **start);
void display(node *start);

node *create_node(int value)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    new_node->left_node = NULL;
    new_node->right_node = NULL;

    return new_node;
}

void insert_beg(node **start, int value)
{
    node *new_node = create_node(value);

    if (new_node != NULL)
    {
        if (*start == NULL)
        {
            printf("first node created\n");
            new_node->left_node = *start;
            new_node->right_node = *start;
            printf("first node at the head\n");
        }
        else
        {
            //code
        }
        
    }
    
}
