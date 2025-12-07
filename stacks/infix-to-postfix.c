#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct node
{
    char data;
    struct node *next_node;
}node;

typedef struct stack
{
    char size;
    node *top;
}stack;

// stack
node *create_node(char value);
void initialize_stack(stack *s);
bool is_empty(stack s);
void push(stack *s, char value);
char peek(stack s);
char pop(stack *s);
void display_stack(stack s);
int size(stack s);

// infix to postfix
int precedence(char op);
void infix_to_postfix(char *intput, char *output, stack *s);

// linked list
void insert_end(node **start, char character);
void delete_end(node **start);
void display_list(node *start);
void list_to_array(node *start, char *array);


node *create_node(char value)
{
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    new_node->next_node = NULL;

    return new_node;
}

void initialize_stack(stack *s)
{
    s->size = -1;
    s->top = NULL;
}

void push(stack *s, char value)
{
    node *new_node = create_node(value);

    if (new_node != NULL)
    {
        new_node->next_node = s->top;
        s->top = new_node;
        s->size++;

        printf("inserted %d in the stack\n", value);
    }
    else
    {
        printf("no memoory\n");
    }
}

bool is_empty(stack s)
{
    bool answer;

    if (s.size < 0)
        answer = true;
    else
        answer = false;
    
    return answer;
}

char peek(stack s)
{
    char peeked_char;

    if (!is_empty(s))
        peeked_char = s.top->data;
    else
        peeked_char = -1;

    return peeked_char;
}

char pop(stack *s)
{
    char poped_char;

    if (!is_empty(*s))
    {
        node *auxiliar;
        auxiliar = s->top;

        s->top = s->top->next_node;
        auxiliar->next_node = NULL;
        poped_char = auxiliar->data;

        s->size--;
        free(auxiliar);
    }
    else
    {
        printf("no stack...\n");
        poped_char = '\0';
    }
    
    return poped_char;
}

void display_stack(stack s)
{
    if (!is_empty(s))
    {
        node *current = s.top;

        while (current != NULL)
        {
            printf("%c -> ", current->data);
            current = current->next_node;
        }
        printf("NULL\n");
    }
    else
        printf("no stack...\n");
}

int size(stack s)
{
    return s.size;
}

void insert_end(node **start, char character)
{
    node *new_node = create_node(character);

    if (new_node != NULL)
    {
        if (*start == NULL)
            *start = new_node;
        else
        {
            node *current;

            current = *start;
            while (current->next_node != NULL)
                current = current->next_node;
        
            current->next_node = new_node;
            printf("inserted\n");
        }
    }
}

void delete_end(node **start)
{
    if (*start == NULL)
        printf("no list\n");
    else if ((*start)->next_node == NULL)
        free(*start);
    else
    {
        node *current = *start;
        node *previous = NULL;

        while (current->next_node != NULL)
        {
            previous = current;
            current = current->next_node;
        }

        previous->next_node = NULL;
        free(current);
        printf("last node eliminated\n");
    }
}

void display_list(node *start)
{
    if (start == NULL)
        printf("NULL\n");
    else
    {
        node *current = start;

        while (current != NULL)
        {
            printf("%c -> ", current->data);
            current = current->next_node;
        }
        printf(" NULL\n");
    }
}

void insert_end(node **start, char character)
{
    node *new_node = create_node(character);

    if (new_node != NULL)
    {
        if (*start == NULL)
            *start = new_node;
        else
        {
            node *current;

            current = *start;
            while (current->next_node != NULL)
                current = current->next_node;
        
            current->next_node = new_node;
            printf("inserted\n");
        }
    }
}

void delete_end(node **start)
{
    if (*start == NULL)
        printf("no list\n");
    else
    {
        node *current = *start;
        node *previous = NULL;

        while (current->next_node != NULL)
        {
            previous = current;
            current = current->next_node;
        }

        previous->next_node = NULL;
        free(current);
        printf("last node eliminated\n");
    }
}

int precedence(char op)
{
    if(op == '^')
        return 3;
    if(op == '*' || op == '/')
        return 2;
    if(op == '+' || op == '-')
        return 1;
}

void infix_to_postfix(char *intput, char *output, stack *s)
{
    int index = 0, i;

    for (i = 0; intput[i] != '\0'; i++)
    {
        char actual = intput[i];

        if (isalnum(actual))
            output[index++] = actual;

        else if (actual == '(')
            push(s, actual);

        else if (actual == ')')
        {
            while (!is_empty(*s) && peek(*s) != '(')
                output[index++] = pop(s);
            
            pop(s);
        }
        else
        {
            while (!is_empty(*s) && precedence(peek(*s)) >= precedence(actual))
                output[index++] = pop(s);
            
            push(s, actual); //push operator
        }
    }
    
    while (!is_empty(*s))
        output[index++] = pop(s);
        
    output[index] = '\0';
}

int main()
{
    char buffer[10000];
    node *cadena = NULL;

    printf("infix expression: ");
    fflush(stdin);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    printf("expression is: %s\n", buffer);


}
