#include <stdio.h>

void DFS(int);
int G[10][10], visited[10], n;

int main()
{
    int i, j;
    printf("Masukkan jumlah simpul: ");
    scanf("%d", &n);

    printf("\nMasukkan matriks ketetanggaan dari graf: ");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &G[i][j]);
        }
    }

    // inisialisasi visited menjadi nol
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    DFS(0);
}

void DFS(int i)
{
    int j;
    printf("\n%d", i);
    visited[i] = 1;

    for (j = 0; j < n; j++)
    {
        if (!visited[j] && G[i][j] == 1)
        {
            DFS(j);
        }
    }
}