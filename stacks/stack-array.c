#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct stack
{
    int values[MAX];
    int top;
    int size;
}stack;

void initialize_stack(stack *s)
{
    s->top = -1;
    s->size = -1;
}

bool is_full(stack s)
{
    bool answer;

    if (s.top == MAX - 1)
        answer = true;   
    else
        answer = false;
    
    return answer;
}

bool is_empty(stack s)
{
    bool answer;

    if (s.top == -1)
        answer = true;
    else
        answer = false;
    
    return answer;
}

int stack_size(stack s)
{
    return s.size + 1;
}

void push(stack *s, int val)
{
    if (!is_full(*s))
    {
        s->top++;
        s->values[s->top] = val;
        s->size++;
        
        printf("inserted %d, in position: %d\n", val, s->top);
    }
    else
        printf("stack overflow...\n");
}

int pop(stack *s)
{
    int poped_val;

    if (!is_empty(*s))
    {
        poped_val = s->values[s->top];
        s->top--;
        s->size--;
    }
    else
        poped_val = -1;

    return poped_val;
}

int peek(stack s)
{
    int peeked_val;

    if (!is_empty(s))
        peeked_val = s.values[s.top];
    else
        peeked_val = -1;

    return peeked_val;
}

void display(stack s)
{
    int i;

    if(!is_empty(s))
    {
        printf("stack: ");
        printf("[");
        for (i = 0; i <= s.size; i++)
        {
            if (i == s.size)
                printf("%d", s.values[i]);
            else
                printf("%d, ", s.values[i]);
        }
        printf("]\n");
    }
    else
        printf("void: []\n");
    
}

int main()
{
    stack s;
    initialize_stack(&s);

    int poped_value;

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    display(s);

    poped_value = pop(&s);
    printf("the poped value is: %d\n", poped_value);

    display(s);

    printf("the size is %d\n", stack_size(s));
}
