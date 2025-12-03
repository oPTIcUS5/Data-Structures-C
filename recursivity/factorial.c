#include <stdio.h>

int factorial_recursive(int n)
{
    if(n == 0)
        return 1;
    
    return n * factorial_recursive(n - 1);
}

int factorial_loop(int n)
{
    int i;
    int previous = 1;

    for (i = 1; i <= n; i++)
    {
        previous *= i;
    }
    
    return previous;
}

int main()
{

    int number;

    printf("number: ");
    scanf("%d", &number);

    printf("factorial (recursive) of %d: %d\n", number, factorial_recursive(number));

    printf("factorial (loop) of %d: %d\n", number, factorial_loop(number));

    return 0;
}
