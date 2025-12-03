//the array must be sorted first
#include <stdio.h>

int binary_search(int arr[], int size, int objective)
{
    int low = 0;
    int high = size - 1;
    int middle;

    while (low <= high)
    {
        middle = (low + high)/2;

        if(arr[middle] == objective)
        {
            return middle;
        }
        else if(arr[middle] < objective)
            low = middle + 1;
        else
            high = middle - 1;
    }

    return -1; //not found
}

void fill_ad_print_array(int array[], int size)
{
    int i;
    int element;

    for(i = 0; i < size; i++)
    {
        printf("element %d: ", i + 1);
        scanf("%d", &element);

        array[i] = element;
    }

    i = 0;


    printf("the array is: ");
    printf("[");
    for (i = 0; i < size; i++)
    {
        if(i == size - 1)
            printf("%d", array[i]);
        else
            printf("%d, ", array[i]);
    }
    printf("]\n");
    
}

void bubble_sort(int array[], int size)
{
    if (size == 0)
    {
        printf("empty array\n");
        return;
    }

    int i, j, temporal;

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temporal = array[j];

                array[j] = array[j + 1];
                array[j + 1] = temporal;
            }
        }
    }
}

void print_array(int array[], int size)
{
    int i;

    printf("the array is: ");
    printf("[");
    for (i = 0; i < size; i++)
    {
        if(i == size - 1)
            printf("%d", array[i]);
        else
            printf("%d, ", array[i]);
    }
    printf("]\n");
}

int main()
{

    return 0;
}
