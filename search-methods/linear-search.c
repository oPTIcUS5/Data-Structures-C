#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int linear_search(int arr[], int size, int objective);
int *create_array(int size);
void display_array(int arr[], int size);
void fill_array(int arr[], int size);

int *create_array(int size)
{
    int i;

    //create the array
    int *array = (int*)malloc(sizeof(int) * size);

    if (array == NULL)
    {
        printf("no memory...\n");
        return NULL;
    }
    else
    {
        for (i = 0; i < size; i++)
        {
            array[i] = 0;
        }
    }

    return array;
}

void display_array(int arr[], int size)
{
    int i;

    printf("[");
    for ( i = 0; i <= size - 1; i++)
    {
        if (i == size - 1)
            printf("%d", arr[i]);
        else
            printf("%d, ", arr[i]);
    }
    printf("]\n");
}

void fill_array(int arr[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("element: ");
        scanf("%d", &arr[i]);
    }
    
    printf("the array is: ");
    display_array(arr, size);
}

int linear_search(int arr[], int size, int objective)
{
    bool flag = false;
    int i = 0, index_position = -1;

    while (i < size && flag == false)
    {
        if (arr[i] == objective)
        {
            flag = true;
            index_position = i;
        }
        else
        {
            flag = false;
        } 
        i++;
    }

    return index_position;
}

int main()
{
    int *arr, idx, size, objecive;

    printf("size of the array: ");
    scanf("%d", &size);

    arr = create_array(size);
    fill_array(arr, size);

    printf("objective: ");
    scanf("%d", &objecive);

    idx = linear_search(arr, size, objecive);

    if (idx != -1)
    {
        printf("founded %d in pos: %d\n", objecive, idx);
    }
    else
    {
        printf("element not found\n");
    }
    

    return 0;
}
