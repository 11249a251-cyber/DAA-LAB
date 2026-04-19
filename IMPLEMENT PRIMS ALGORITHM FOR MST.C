#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define N 5

int getMin(int keyArr[], bool used[]) {
    int min = INT_MAX, pos;

    for (int i = 0; i < N; i++)
        if (used[i] == false && keyArr[i] < min)
            min = keyArr[i], pos = i;

    return pos;
}

void printTree(int parentArr[], int graph[N][N]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < N; i++)
        printf("%d - %d \t%d \n", parentArr[i], i, graph[parentArr[i]][i]);
}

void runPrim(int graph[N][N]) {
    int parentArr[N];
    int keyArr[N];
    bool used[N];

    for (int i = 0; i < N; i++)
        keyArr[i] = INT_MAX, used[i] = false;

    keyArr[0] = 0;
    parentArr[0] = -1;

    for (int c = 0; c < N - 1; c++) {
        int u = getMin(keyArr, used);
        used[u] = true;

        for (int j = 0; j < N; j++)
            if (graph[u][j] && used[j] == false && graph[u][j] < keyArr[j])
                parentArr[j] = u, keyArr[j] = graph[u][j];
    }

    printTree(parentArr, graph);
}

int main() {
    int graph[N][N] = {
        { 0, 2, 0, 6, 0 },
        { 2, 0, 3, 8, 5 },
        { 0, 3, 0, 0, 7 },
        { 6, 8, 0, 0, 9 },
        { 0, 5, 7, 9, 0 }
    };

    runPrim(graph);

    return 0;
}
