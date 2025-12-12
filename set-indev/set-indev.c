#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "t_colors.h"

typedef struct node
{
    char data;
    struct node *next_node;
}node;

node *create_node(char value);
void add_to_list(node **start, char value); //to add at the ends
void delete_from_list(node **start); // to delete at the end;
void display(node *start); //to show the list
bool is_in_list(node *start, char objective); //proove if an element is in the list
node *search_in_list(node *start, char objective); //search the node that has the objective
void create_set_array(node **start, char *str_usr); //create the set
void add_to_set(node **start, char value);
void union_set(node **head_set1, node **head_set2); //union of two sets;

node *create_node(char value)
{
    node *new = (node*)malloc(sizeof(node));
    new->data = value;
    new->next_node = NULL;

    return new;
}

void add_to_list(node **start, char value)
{
    node *new_node, *current_node = NULL;

    new_node = create_node(value); //create the node;

    if (new_node != NULL)
    {
        if (*start == NULL)
        {
            printf(CYAN ">> list empty... first node created <<\n" NORMAL);
            *start = new_node;
            printf(CYAN ">> first node with the value of %c at the head of the list <<\n" NORMAL, value);
        }
        else
        {
            current_node = *start;

            while (current_node->next_node != NULL)
                current_node = current_node->next_node;
            
            current_node->next_node = new_node;
            printf(GREEN "****inserted %c at the end****\n" NORMAL, value);
        }
    }
    else
        printf("fail... no memory\n");
}

void display(node *start)
{
    node *current = NULL;

    if (start == NULL)
        printf("NULL (no list)\n");
    else
    {
        current = start;

        while (current != NULL)
        {
            printf(YELLOW "%c -> " NORMAL, current->data);
            current = current->next_node;
        }
        printf("NULL\n");
    }
}

bool is_in_list(node *start, char objective)
{
    node *current = NULL;
    bool flag = false;

    if (start == NULL) // no one node
        printf(RED "<<no list>>\n" NORMAL);
    else if (start->next_node == NULL) //just one node
    {
        if (start->data == objective)
            flag = true;
        else
            flag = false;
    }
    else
    {
        current = start;
        while (current != NULL && flag == false)
        {
            if (current->data == objective)
                flag = true;
            else
                current = current->next_node;
        }
    }
    
    return flag;
}

node *search_in_list(node *start, char objective)
{
    node *current = NULL; //current node;
    node *founded = NULL; // node to return;
    bool flag = false;

    if (start == NULL) // no list
    {
        flag = false;
        printf(RED "empty list...\n" NORMAL);
    }
    else if (start->next_node == NULL) // just one node
    {
        printf(CYAN "just one node in the list\n" NORMAL);
        if (start->data == objective)
        {
            flag = true;
            founded = start;
        }
        else
            flag = false;   
    }
    else
    {
        current = start;
        while (current != NULL && flag == false)
        {
            if (current->data == objective)
            {
                flag = true;
                founded = current;
            }
            else
                current = current->next_node;
        }
    }

    return founded;
}

void create_set_array(node **start, char *str_user)
{
    int i = 0;
    char letter;

    while (str_user[i] != '\0')
    {
        letter = str_user[i];

        if (!is_in_list(*start, letter))
            add_to_list(start, letter);

        i++;
    }
    
    printf(YELLOW ">>>>set created<<<<\n" NORMAL);
}

void add_to_set(node **start, char value)
{
    //code
}

void union_set(node **head_set1, node **head_set2)
{
    node *current = NULL;

    if (*head_set1 == NULL && *head_set2 == NULL)
        printf(RED "both sets empty" NORMAL);
    else if (*head_set1 == NULL || *head_set2 == NULL)
        printf(RED "One set empty, no union\n" NORMAL);
    else if (*head_set1 != NULL && *head_set2 != NULL)
    {
        current = *head_set2;
        while (current != NULL)
        {
            if (!is_in_list(*head_set1, current->data))
                add_to_list(head_set1, current->data);

            current = current->next_node;
        }   
    }
}

int main()
{
    node *set1 = NULL;
    node *set2 = NULL;

    add_to_list(&set1, 'a');
    add_to_list(&set1, 'b');
    add_to_list(&set1, 'c');

    add_to_list(&set2, 'c');
    add_to_list(&set2, 'd');
    add_to_list(&set2, 'd');

    union_set(&set1, &set2);
    display(set1);

    return 0;
}