#include <stdio.h>
#include <stdlib.h>

typedef struct MaxHeap
{
    int *array;
    int capacity;
    int actual_size;
}MaxHeap;

MaxHeap *createMaxHeap(int capacity);

MaxHeap *createMaxHeap(int capacity)
{
    MaxHeap *HEAP = (MaxHeap*)malloc(sizeof(MaxHeap));
    HEAP->capacity = capacity;
    HEAP->actual_size = 0;
    HEAP->array = (int*)malloc(capacity * sizeof(int));

    return HEAP;
}
