#include <stdio.h>
#include <stdbool.h>

#define MAX 9999

char array[MAX];

typedef struct STACK
{
    int top;
    int size;
}STACK;

void push(STACK *s, char value);
char pop(STACK *s);
char peek(STACK s);
bool is_empty(STACK s);
void display_stack(STACK s);
