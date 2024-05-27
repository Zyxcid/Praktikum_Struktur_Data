#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c, first, last, middle, n, search, array[100];

    system("cls");
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);
    printf("Masukkan %d bilangan: \n", n);

    for (c = 0; c < n; c++)
    {
        printf("-> ");
        scanf("%d", &array[c]);
    }

    printf("\n~> Masukkan nilai yang ingin dicari: ");
    scanf("%d", &search);

    system("cls");

    first = 0;
    last = n - 1;
    middle = (first + last) / 2;

    while (first <= last)
    {
        if (array[middle] < search)
            first = middle + 1;
        else if (array[middle] == search)
        {
            printf("[Ditemukan!] data %d ditemukan pada posisi ke-%d \n", search, middle + 1);
            break;
        }
        else
            last = middle - 1;
        middle = (first + last) / 2;
    }
    if (first > last)
        printf("[Tidak ditemukan!] data %d tidak ada dalam daftar\n", search);
    return 0;
}