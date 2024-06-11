#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int a[20][20], reach[20], n;
void dfs(int v)
{
    int i;
    reach[v] = 1;
    for (i = 1; i <= n; i++)
    {
        if (a[v][i] && !reach[i])
        {
            printf("\n\n%d->%d", v, i);
            dfs(i);
        }
    }
}

int main()
{
    int i, j, count = 0;

    system("cls");
    printf("~> Masukkan jumlah simpul : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        reach[i] = 0;
        for (j = 1; j <= n; j++)
        {
            a[i][j] = 0;
        }
    }

    printf("~> Masukkan matriks ketetanggaan : \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("   -> ");
            scanf("%d", &a[i][j]);
        }
    }
    dfs(1);
    for (i = 1; i <= n; i++)
    {
        if (reach[i])
        {
            count++;
        }
    }
    if (count == n)
    {
        printf("\n[ Graf Terhubung ]");
    }
    else
    {
        printf("\n[ Graf Tidak Terhubung ]");
    }

    getch();
}