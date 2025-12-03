#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int array[MAX];

typedef struct queue
{
    int front;
    int rear;
    int size;
}queue;

void initialize_queue(queue *q)
{
    q->front = q->rear = q->size = -1;
}

bool is_empty(queue q)
{
    bool answer;

    if(q.size == -1)
        answer = true;
    else
        answer = false;
    
    return answer;
}

int is_full(queue q)
{
    bool answer;

    if(q.size == MAX - 1)
        answer = true;
    else
        answer = false;

    return answer;
}

void enqueue(queue *q, int element)
{
    if(!is_full(*(q)))
    {
        array[++q->rear] = element;
        q->size++;
        q->front++;

        printf("enqueued %d, in position: %d\n", element, q->rear);
    }
    else
        printf("queue overflow...\n");
}

void display(queue q)
{
    int i;

    if (!is_empty(q))
    {
        printf("[");

        for ( i = 0; i <= q.rear; i++)
        {
            if (i == q.rear)
                printf("%d", array[i]);
            else
                printf("%d, ", array[i]);
        }
        printf("]\n");
    }
    else
        printf("void: []\n");
    
}

int main()
{
    queue q;
    initialize_queue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(q);

    return 0;
}
