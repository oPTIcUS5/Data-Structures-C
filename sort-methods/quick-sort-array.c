#include <stdio.h>

void swap(int* ptr_a, int* ptr_b);
int partition(int arr[], int low, int high);
void quick_sort(int arr[], int low, int high);
void fill_array(int * arr, int size);
void display_array(int arr[], int size);


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


void quick_sort(int arr[], int low, int high)
{
    int piv;

    piv = partition(arr, low, high);

    if (low < high)
    {
        quick_sort(arr, low, piv - 1);
        quick_sort(arr, piv + 1, high);
    }
}

void display_array(int array[], int size)
{
    int i;

    printf("[");
    for (i = 0; i < size; i++)
    {
        if (i == size - 1)
            printf("%d", array[i]);
        else
            printf("%d, ", array[i]);
    }
    printf("]\n");
    
}

void fill_array(int * arr, int size)
{
    int i;

    for ( i = 0; i < size; i++)
    {
        printf("insert the element %d: ", i);
        scanf("%d", &arr[i]);
    }
    
    printf("end of the function fill array\n");
}


int main(void)
{
    int size;

    do
    {
        printf("Insert the size of the array: ");
        scanf("%d", &size);

        if (size < 0)
        {
            printf("ERROR: invalid size\n");
        }
        
    } while (size < 0);

    int array[size];

    fill_array(array, size);
    
    printf("the array is: ");
    display_array(array, size);

    quick_sort(array, 0, size - 1);

    printf("the sorted array is: ");
    display_array(array, size);
}
