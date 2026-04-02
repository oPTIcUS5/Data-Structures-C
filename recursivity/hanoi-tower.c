#include <stdio.h>

int hanoi_tower(int n, char origin, char auxiliar, char destiny)
{
    if (n == 1)
    {
        printf("Move disk %c to %c\n", origin, destiny);
    }
    else
    {
        hanoi_tower(n - 1, origin, destiny, auxiliar);
        printf("move disk %c to %c\n", origin, destiny);
        hanoi_tower(n - 1, auxiliar, origin, destiny);
    }
}

int main()
{

    int disks;

    do
    {
        printf("number of disks: ");
        scanf("%d", &disks);

        if (disks < 1)
            printf("Error: the n. of disks must be > 1");
        
    } while (disks < 1);
    
    hanoi_tower(disks, 'A', 'B', 'C');

    return 0;
}
