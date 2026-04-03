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

    temp = *b;
    *a = *b;
    *b = temp;
}



