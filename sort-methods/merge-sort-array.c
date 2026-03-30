#include <stdio.h>
#include <stdlib.h>

void merge(int array[], int left, int mid, int right);
void merge_sort(int array[], int left, int right);
void display_array(int array[], int size);


void merge(int array[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for ( i = 0; i < n1; i++)
    {
        L[i] = array[left + i];
    }
    

    for ( j = 0; j < n2; j++)
    {
        R[j] = array[mid + 1 + j];
    }
    

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }

        k++;
    }



    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }


    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}


void merge_sort(int array[], int left, int right)
{
    int mid;

    if (left < right)
    {
        mid = left + (right - left) / 2;

        merge_sort(array, left, mid);

        merge_sort(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}


void display_array(int array[], int size)
{
    int i, size;

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

int main(void)
{
    int array[] = {6, 23, -1, 4, 100};
    display_array(array, 5);

    merge_sort(array, 0, 5 - 1);
    printf("sorted array: \n");
    display_array(array, 5);

}
