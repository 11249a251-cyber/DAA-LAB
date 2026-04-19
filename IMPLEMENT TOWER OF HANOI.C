#include <stdio.h>

void solveHanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("\nMove disk %d from %c to %c", n, from, to);
        return;
    }

    solveHanoi(n - 1, from, aux, to);
    printf("\nMove disk %d from %c to %c", n, from, to);
    solveHanoi(n - 1, aux, to, from);
}

int main()
{
    int num;

    printf("enter number of disks: ");
    scanf("%d", &num);

    solveHanoi(num, 'A', 'C', 'B');

    return 0;
}
