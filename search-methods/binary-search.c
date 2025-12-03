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

int main()
{
    return 0;
}
