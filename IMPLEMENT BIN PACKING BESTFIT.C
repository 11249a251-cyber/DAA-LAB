#include<stdio.h>

void placeItems(int arr[], int n, int cap){
    int bins[n];
    int count = 0;

    for(int i = 0; i < n; i++) bins[i] = cap;

    for(int i = 0; i < n; i++){
        int index = -1;
        int space = cap + 1;

        for(int j = 0; j < count; j++){
            if(bins[j] >= arr[i] && (bins[j] - arr[i]) < space){
                index = j;
                space = bins[j] - arr[i];
            }
        }

        if(index != -1){
            bins[index] -= arr[i];
            printf("Item %d (weight %d) placed in Bin %d\n", i + 1, arr[i], index + 1);
        }else{
            bins[count] -= arr[i];
            printf("Item %d (weight %d) placed in Bin %d\n", i + 1, arr[i], count + 1);
            count++;
        }
    }

    printf("Total bins used = %d\n", count);
}

int main(){
    int n, cap;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter bin capacity: ");
    scanf("%d", &cap);

    printf("Enter item sizes:\n");
    for(int i = 0; i < n; i++){
        int val;
        printf("Item %d: ", i + 1);
        scanf("%d", &val);

        if(val <= cap){
            arr[i] = val;
        }else{
            printf("Item size exceeds bin capacity. Please enter again.\n");
            i--;
        }
    }

    placeItems(arr, n, cap);

    return 0;
}
