#include<stdio.h>
struct data
{
    int p;
    int w;
    float r;
};
void arrange(struct data a[], int n)
{
    struct data temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j].r < a[j + 1].r)
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int cap, n;
    printf("enter capacity:");
    scanf("%d", &cap);
    printf("enter no of items:");
    scanf("%d", &n);
    struct data arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("enter item %d weight profit:", i + 1);
        scanf("%d %d", &arr[i].w, &arr[i].p);
        arr[i].r = (float)arr[i].p / arr[i].w;
    }
    arrange(arr, n);
    float total = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (cap >= arr[i].w)
        {
            total += arr[i].p;
            cap -= arr[i].w;
        }
        else
        {
            total += arr[i].r * cap;
            break;
        }
    }
    printf("Maximum profit = %.2f\n", total);
    return 0;
}
