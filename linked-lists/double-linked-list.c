#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
}node;

void insert_at_end(node **head, int value)
{
    //create the node
    node *new_node = (node*)malloc(sizeof(node));

    //validate that wasnt null
    if (new_node != NULL)
    {
        new_node->data = value;

        if (*head == NULL)
        {
            new_node->left = NULL;
            new_node->right = NULL;
            *head = new_node;
        }
        else
        {
            node *auxiliar = *head;
            while (auxiliar->right != NULL)
            {
                auxiliar = auxiliar->right;
            }

            auxiliar->right = new_node;
            new_node->left = auxiliar;
        }
    }
    else
        printf("no memory\n");
}

void insert_at_beggining(node **head, int value)
{
    node *new_node = (node*)malloc(sizeof(node));

    if (new_node != NULL)
    {
        new_node->data = value;

        if (*head == NULL)
        {
            new_node->left = NULL;
            new_node->right = NULL;
            *head = new_node;
        }
        else
        {
            (*head)->left = new_node;
            new_node->right = *head;
            *head = new_node;
        }
    }
    else
        printf("no memory\n");
    
}

void display_list(node *head)
{
    if (head == NULL)
        printf("no list\n");
    else
    {
        node *current = head;

        printf("null ");
        while (current != NULL)
        {
            printf(" <- %d -> ", current->data);
            current = current->right;
        }
        printf("null\n");
    }
}

void delete_at_beggining(node **head)
{
    if (*head == NULL)
    {
        printf("no list\n");
    }
    else
    {
        node *temp = *head;
        *head = (*head)->right;
        (*head)->left = NULL;

        free(temp);
        printf("first node removed\n");
    }
}

void delete_at_the_end(node **head)
{
    if(*head != NULL)
    {
        if((*head)->right == NULL)
            free(*head);
        else
        {
            node *auxiliar = *head;

            while (auxiliar->right != NULL)
            {
                auxiliar = auxiliar->right;
            }

            node *tail = auxiliar->left;
            auxiliar->left = NULL;
            tail->right = NULL;
            free(auxiliar);

            printf("last node eliminated\n");
        }
    }
    else
        printf("no list\n");
}

int main()
{
    node *double_list = NULL;
    int choice, element;

    do
    {
        printf("\n=====Menu=====\n");
        printf("1) Insert at beg\n");
        printf("2) insert at end\n");
        printf("3) delete at beg\n");
        printf("4) delete at end\n");
        printf("5) display list\n");
        printf("6) exit\n");
        printf("option: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                printf("element: ");
                scanf("%d", &element);
                insert_at_beggining(&double_list, element);
            }
                break;
            
            case 2:
            {
                printf("element: ");
                scanf("%d", &element);
                insert_at_end(&double_list, element);
            }
            break;

            case 3:
                delete_at_beggining(&double_list);
                break;
            
            case 4:
                delete_at_the_end(&double_list);
                break;
            
            case 5:
                display_list(double_list);
                break;
        }

    } while (choice != 6);
    
    printf("\nexiting...\n");

    return 0;
}
