#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next_node;
}node;

typedef struct stack
{
    node *top;
    int size;
}stack;

void initialize_stack(stack *s)
{
    s->size = -1;
    s->top = NULL;
}

bool is_empty(stack *s)
{
    bool answer = false;

    if (s->size == -1)
        answer = true;
    else
        answer = false;

    return answer;
}

int size_stack(stack s)
{
    int size;

    if (!is_empty(&s))
        size = s.size + 1;
    else
        size = -1;

    return size;
}

void push(stack *s, int val)
{
    node *new_nodo = (node*)malloc(sizeof(node));
    
    if (new_nodo == NULL)
    {
        printf("no memory...\n");
    }
    else
    {
        new_nodo->data = val;
        new_nodo->next_node = s->top;
        s->top = new_nodo;

        s->size++;

        printf("inserted: %d in the stack, possition: %d\n", s->top->data, s->size);
    }
}
 
int pop(stack *s)
{
    int val_poped;

    if(!is_empty(s))
    {
        node *auxiliar_node;
        auxiliar_node = s->top;

        s->top = s->top->next_node;
        auxiliar_node->next_node = NULL;
        val_poped = auxiliar_node->data;

        s->size--;

        free(auxiliar_node);
    }
    else
    {
        printf("no stack...\n");
        val_poped = -1;
    }

    return val_poped;
}

int peek(stack s)
{
    int peek_value;

    if (!is_empty(&s))
        peek_value = s.top->data;
    else
        peek_value = -1;
    
    return peek_value;
}

void display(stack s)
{
    if (!is_empty(&s))
    {
        node *current = s.top;

        while (current != NULL)
        {
            printf("%d -> ", current->data);
            current = current->next_node;
        }
        printf("NULL\n");
        
    }
    else
    {
        printf("no stack..\n");
    }
    
}

int main()
{
    stack s;
    initialize_stack(&s);

    int option;

    do
    {
        printf("\n===Menu===\n");
        printf("1) push\n");
        printf("2) pop\n");
        printf("3) peek\n");
        printf("4) display stack\n");
        printf("5) display size of stack\n");
        printf("6) quit\n");
        printf("option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
        {
            int element;
            printf("element to insert in the stack: ");
            scanf("%d", &element);

            push(&s, element);
        }
            break;
        
        case 2:
        {
            int poped_value;
            poped_value = pop(&s);

            printf("the poped element is: %d\n", poped_value);
        }
            break;
        
        case 3:
        {
            int peeked_value;
            peeked_value = peek(s);

            printf("the peeked value is: %d\n", peeked_value);
        }
            break;
        
        case 4:
        {
            printf("the stack in memory is: \n");
            display(s);
        }
            break;
        
        case 5:
            printf("the size of the stack is: %d\n", size_stack(s));
            break;
        
        case 6:
            printf("exiting...\n");
            break;
        
        default:
            printf("value no recognized\n");
            break;
        }

        if (option < 1 || option > 6)
        {
            printf("ERROR: the options are just 1), 2), 3), 4), 5) and 6)\n");
        }
        
    } while (option != 6);
    
    
    return 0;
}
