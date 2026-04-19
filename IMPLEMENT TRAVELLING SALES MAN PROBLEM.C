#include <stdio.h>
#include <limits.h>

#define SIZE 15
#define MAX INT_MAX

int n;
int cost[SIZE][SIZE];
int memo[SIZE][1 << SIZE];

int tspCalc(int curr, int mask)
{
    if (mask == 0)
        return cost[curr][0];

    if (memo[curr][mask] != -1)
        return memo[curr][mask];

    int ans = MAX;

    for (int i = 0; i < n; i++)
    {
        if (mask & (1 << i))
        {
            int val = cost[curr][i] + tspCalc(i, mask & ~(1 << i));
            if (val < ans)
            {
                ans = val;
            }
        }
    }

    return memo[curr][mask] = ans;
}

int main()
{
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    for (int i = 0; i < n; i++)
        for (int m = 0; m < (1 << n); m++)
            memo[i][m] = -1;

    int set = 0;
    for (int i = 1; i < n; i++)
        set |= (1 << i);

    int result = tspCalc(0, set);

    printf("Given Cost Matrix\n");
    for (int i = 0; i < n; i++)
    {
        printf("|");
        for (int j = 0; j < n; j++)
            printf(" %d ", cost[i][j]);
        printf("|\n");
    }

    printf("Minimum travelling cost: %d\n", result);

    return 0;
}
