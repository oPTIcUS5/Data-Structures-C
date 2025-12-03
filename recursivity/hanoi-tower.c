/*
this program gives you the number of necesary movements
of the hanoi tower
*/

#include <stdio.h>

int hanoi_tower(int disks)
{
    if (disks == 1)
    {
        return 1;
    }
    return 2 * hanoi_tower(disks - 1) + 1;
}

int main()
{

    int disks, movements;

    printf("number of disks: ");
    scanf("%d", &disks);

    movements = hanoi_tower(disks);

    printf("the total of necesary movements is: %d\n", movements);

    return 0;
}
