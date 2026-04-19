#include <stdio.h>

int fib(int x)
{
    if(x == 0)
        return 0;
    if(x == 1)
        return 1;
    return fib(x - 1) + fib(x - 2);
}

int main()
{
    int num;
    printf("enter number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("invalid");
    }

    printf("fibonacci term is: %d", fib(num));
    return 0;
}
