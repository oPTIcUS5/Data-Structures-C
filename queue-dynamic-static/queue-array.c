#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int array[MAX]; //global array

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

    if(q.rear == -1)
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
    //function to enqueue
    if(!is_full(*(q)))
    {
        if (is_empty(*(q)))
        {
            array[++q->front] = element;
            q->size++;
            q->rear++;
        }
        else
        {
            array[++q->rear] = element;
            q->size++;
        }

        printf("enqueued %d, in position: %d\n", element, q->rear);
    }
    else
    {
        printf("queue overflow...\n");
        printf("%d not enqueued\n", element);
        printf("please, dequeue at least one element\n");
    }
}

void dequeue(queue *q)
{
    if (!is_empty(*(q)))
    {
        printf("dequeued %d\n", array[q->front]);
        ++q->front;
        --q->size;
    }
    else
        printf("no queue...\n");
}

int peek(queue q)
{
    if (!is_empty(q))
        return array[q.front];
    else
        return -1;
}

void display(queue q)
{
    int i;

    if (!is_empty(q))
    {
        printf("[");

        for (i = q.front; i <= q.rear; i++)
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
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);

    printf("the peeked value is: %d\n", peek(q));

    display(q);

    dequeue(&q);

    display(q);

    return 0;
}
