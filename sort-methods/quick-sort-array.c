#include <stdio.h>

void swap(int* ptr_a, int* ptr_b);


void swap(int* ptr_a, int* ptr_b)
{
    int temp;

    temp = *ptr_a;

    *ptr_a = *ptr_b;
    *ptr_b = temp;
}

int partition(int *arr, int low, int high)
{
    int pivot, i, j;

    pivot = arr[high];
    i = low - 1;

    for ( j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[j]);
    
    return i + 1;
}




