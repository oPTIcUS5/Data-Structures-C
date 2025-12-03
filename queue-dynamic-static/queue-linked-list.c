#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next_node;
}node;

typedef struct queue
{
    node *front;
    node *final;
    int size;
}queue;

void initiaize_queue(queue *q)
{
    q->front = NULL;
    q->final = NULL;
    q->size = -1;
}

bool is_empty(queue q)
{
    bool value;

    if (q.size == -1)
        value = true;
    else
        value = false;

    return value;
}

void enqueue(queue *q, int val)
{
    node *new_node = (node*)malloc(sizeof(node));

    if (new_node != NULL)
    {
        new_node->data = val;
        new_node->next_node = NULL;

        if (q->final == NULL)
            q->front = new_node;
        else
            q->final->next_node = new_node;
        
        q->final = new_node;
        q->size++;

        printf("enqueue %d, in position: %d\n", val, q->size);
    }
    else
    {
        printf("no memory available\n");
    }
}

int dequeue(queue *q)
{
    int dequeued_val;

    if (is_empty(*(q)))
    {
        printf("no queue in memory...\n");
        dequeued_val = -1;
    }
    else
    {
        node *auxiliar_node = q->front;
        q->front = auxiliar_node->next_node;
        auxiliar_node->next_node = NULL;

        dequeued_val = auxiliar_node->data;
        free(auxiliar_node);
        q->size--;
    }

    return dequeued_val;
}

int peek(queue q)
{
    int peeked_val;

    if (!is_empty(q))
        peeked_val = q.front->data;
    else
    {
        printf("no queue in memory\n");
        peeked_val = -1;
    }

    return peeked_val;
}

int queue_size(queue q)
{
    return q.size + 1;
}

void display(queue q)
{
    if (!is_empty(q))
    {
        if (queue_size(q) == 1)
            printf("%d -> NULL\n", q.front->data);
        else
        {
            node *auxiliar = q.front;
            while (auxiliar != NULL)
            {
                printf("%d -> ", auxiliar->data);
                auxiliar = auxiliar->next_node;
            }
            printf("NULL\n");
        }
    }
    else
        printf("no queue in memory...\n");
}

int main()
{
    queue q;
    initiaize_queue(&q);

    int option, element;

    do
    {
        printf("===Menu===\n");
        printf("1) enqueue\n");
        printf("2) dequeue\n");
        printf("3) display peek\n");
        printf("4) display size\n");
        printf("5) display queue\n");
        printf("6) quit\n");
        printf("option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
        {
            printf("element to insert: ");
            scanf("%d", &element);
            enqueue(&q, element);
        }
            break;
        case 2:
            printf("the dequeued element is: %d\n", dequeue(&q));
            break;
        case 3:
            printf("the peeked elemet is: %d\n", peek(q));
            break;
        case 4:
            printf("the size of the queue is: %d\n", queue_size(q));
            break;
        case 5:
        {
            printf("the queue is: \n");
            display(q);
        }
            break;
        
        if (option < 1 || option > 6)
            printf("ERROR: option no recognized\n");
        
        }
    } while (option != 6);
    

    return 0;
}
