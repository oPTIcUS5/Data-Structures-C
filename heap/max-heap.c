#include <stdio.h>
#include <stdlib.h>

typedef struct MaxHeap
{
    int *array;
    int capacity;
    int actual_size;
}MaxHeap;

MaxHeap *createMaxHeap(int capacity);
int getFather(int i);
int getLeftChild(int i);
int getRightchild(int i);
void siftDown(MaxHeap *Heap, int i);
int deleteRoot(MaxHeap *Heap);
void insert(MaxHeap *Heap, int value);
void swap(int *a, int *b);
void displayHeap(MaxHeap *Heap);

MaxHeap *createMaxHeap(int capacity)
{
    MaxHeap *HEAP = (MaxHeap*)malloc(sizeof(MaxHeap));
    HEAP->capacity = capacity;
    HEAP->actual_size = 0;
    HEAP->array = (int*)malloc(capacity * sizeof(int));

    return HEAP;
}


void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int getFather(int i)
{
    return (i - 1) / 2;
}

int getLeftChild(int i)
{
    return (2*i) + 1;
}

int getRightchild(int i)
{
    return (2*i) + 2;
}

void siftDown(MaxHeap *Heap, int i)
{
    int big = i;
    int left = getLeftChild(i);
    int right = getRightchild(i);

    if (left < Heap->actual_size && Heap->array[left] > Heap->array[big])
        big = left;

    if (right < Heap->actual_size && Heap->array[right] > Heap->array[big])
        big = right;

    if (big != i)
    {
        swap(&Heap->array[i], &Heap->array[big]);
        siftDown(Heap, big);
    }
}


void insert(MaxHeap *Heap, int value)
{
    if (Heap->actual_size == Heap->capacity)
    {
        printf("Error: Heap overflow\n");
    }
    else
    {
        int i = Heap->actual_size;
        Heap->array[i] = value;
        Heap->actual_size++;

        while (i != 0 && Heap->array[getFather(i)] < Heap->array[i])
        {
            swap(&Heap->array[i], &Heap->array[getFather(i)]);
            i = getFather(i);
        }
    }
}


int deleteRoot(MaxHeap *Heap)
{
    int root;

    if (Heap->actual_size == 0)
    {
        return -1;
    }
    
    if (Heap->actual_size == 1)
    {
        Heap->actual_size--;
        return Heap->array[0];
    }

    root = Heap->array[0]; //root to return (max)

    Heap->array[0] = Heap->array[Heap->actual_size - 1];
    Heap->actual_size--;

    siftDown(Heap, 0);
    
    return root;
}

void displayHeap(MaxHeap *Heap)
{
    int i;

    printf("[");
    for ( i = 0; i < Heap->actual_size; i++)
    {
        if(i == Heap->actual_size - 1)
            printf("%d", Heap->array[i]);
        else
            printf("%d, ", Heap->array[i]);
    }
    printf("]\n");
}


int main(void)
{
    int choice, HeapSize, element, root;
    MaxHeap *Heap = NULL;

    do
    {
        printf("\n===Menu===\n");
        printf("1) Create MaxHeap\n");
        printf("2) Insert elements\n");
        printf("3) Delete root\n");
        printf("4) Display MaxHeap (array)\n");
        printf("5: Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                printf("input the size of the MaxHeap: ");
                scanf("%d", &HeapSize);

                Heap = createMaxHeap(HeapSize);
                printf("MaxHeap Created\n");
            }
                break;
            
            case 2:
            {
                if (Heap == NULL)
                    printf("First create the heap...\n");
                else
                {
                    printf("Element: ");
                    scanf("%d", &element);

                    insert(Heap, element);
                }
            }
                break;

            case 3:
            {
                if (Heap == NULL)
                    printf("First create the heap...\n");
                else
                {
                    root = deleteRoot(Heap);
                    printf("Root: %d\n", root);
                }
            }
            break;

            case 4:
            {
                if (Heap == NULL)
                    printf("First create the heap...\n");
                else
                    displayHeap(Heap);
            }
            break;
        }
    } while (choice <= 4);

    free(Heap->array);
    free(Heap);

    printf("MaxHeap deleted...\n");
}
