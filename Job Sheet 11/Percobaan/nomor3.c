#include <stdio.h>
#include <stdlib.h>

int cari(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main(void)
{
    int arr[] = {2, 3, 4, 10, 40};
    int x = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    int hasil = cari(arr, n, x);

    system("cls");
    if (hasil == -1)
    {
        printf("~> Elemen tidak ditemukan dalam array");
    }
    else
    {
        printf("~> Elemen ditemukan pada indeks ke-[%d]", hasil);
    }
    return 0;
}