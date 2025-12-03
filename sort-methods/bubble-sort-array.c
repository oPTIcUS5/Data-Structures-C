#include <stdio.h>

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
    int size;

    printf("size of the array: ");
    scanf("%d", &size);

    int array[size];

    fill_ad_print_array(array, size);

    bubble_sort(array, size);

    print_array(array, size);

    return 0;
}
