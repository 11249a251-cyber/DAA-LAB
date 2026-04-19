#include<stdio.h>

void packItems(int arr[], int n, int cap)
{
    int bins[n];
    int count = 0;

    for(int i = 0; i < n; i++)
        bins[i] = cap;

    for(int i = 0; i < n; i++)
    {
        int flag = 0;

        for(int j = 0; j < count; j++)
        {
            if(bins[j] >= arr[i])
            {
                bins[j] -= arr[i];
                printf("item %d placed in bin %d\n", arr[i], j + 1);
                flag = 1;
                break;
            }
        }

        if(!flag)
        {
            bins[count] -= arr[i];
            printf("item %d placed in bin %d\n", arr[i], count + 1);
            count++;
        }
    }

    printf("total bins used = %d\n", count);
}

int main()
{
    int n, cap;

    printf("enter number of items: ");
    scanf("%d", &n);

    int arr[n];

    printf("enter item size:\n");
    for(int i = 0; i < n; i++)
    {
        printf("item %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("enter bin capacity: ");
    scanf("%d", &cap);

    packItems(arr, n, cap);

    return 0;
}
