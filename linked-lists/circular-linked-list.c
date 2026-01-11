#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next_node;
}node;

node *create_node(int value);
void insert_beg(node **start, int value);
void insert_end(node **start, int value);
void delete_beg(node **start);
void delete_end(node **start);
void display(node *start);

node *create_node(int value)
{
    node *new_node = (node*)malloc(sizeof(node));

    new_node->data = value;
    new_node->next_node = NULL;
    
    return new_node;
}

void insert_beg(node **head, int value)
{
    node *new_node = (node*)malloc(sizeof(node));
    node *current;

    if (new_node == NULL)
    {
        printf("no memory available\n");
        return;
    }
    else
    {
        if(*head == NULL)
        {
            new_node->data = value;
            new_node->next_node = new_node;
            *head = new_node;
            printf("inserted %d at the head\n", value);
        }
        else
        {
            new_node->data = value;
            new_node->next_node = NULL;

            current = *head;
            while (current->next_node != *head)
            {
                current = current->next_node;
            }

            new_node->next_node = *head;
            current->next_node = new_node;
            *head = new_node;
            printf("inserted %d at the beg\n", value);
        }
    }
    
}

void insert_end(node **start, int value)
{
    node *current = NULL;
    node *new_node = create_node(value);

    if (new_node != NULL)
    {
        current = *start;

        while (current->next_node != *start)
        {
            current = current->next_node;
        }

        current->next_node = new_node;
        new_node->next_node = *start;
        printf("inserted %d at the end\n", value);
    }
    else
        printf("no memory\n");
    
}

void display(node *head)
{
    node *current = NULL;

    if(head == NULL)
    {
        printf("empty list\n");
    }
    else if((head)->next_node == head)
        printf("HEAD -> %d -> HEAD\n", (head)->data);
    else
    {
        current = head;
        while(1)
        {
            printf("%d -> ", current->data);
            current = current->next_node;

            if (current == head)
                break;
        }
        printf("HEAD\n");
    }
}

int main()
{

    node *circular_list = NULL;

    insert_beg(&circular_list, 1);
    insert_beg(&circular_list, 2);
    insert_end(&circular_list, 3);

    display(circular_list);

    return 0;
}
