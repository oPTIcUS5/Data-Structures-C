#include <stdio.h>
#include <stdlib.h>

void merge(int array[], int left, int mid, int right);
void merge_sort(int array[], int left, int right);
void display_array(int* array);


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
    k = mid;

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
    int mid = NULL;

    if (left < right)
    {
        mid = left + (right - left) / 2;

        merge_sort(array, left, mid);

        merge_sort(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}


void display_array(int* array)
{
    int i, size = NULL;

    size = sizeof(array)/sizeof(array[0]);

    for ( i = 0; i < size; i++)
    {
        /* code */
    }
    
}
