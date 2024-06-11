#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tabInt[10] = {22, 55, 21, 56, 60, 67, 96, 92, 99};
    int i, j, k;
    int cariData, ketemu;

    system("cls");
    printf("Masukkan data yang dicari = ");
    scanf("%d", &cariData);

    i = 0;
    j = 9;
    ketemu = 0;

    while ((ketemu == 0) && (i <= j))
    {
        k = (int)(i + j) / 2;
        if (tabInt[k] == cariData)
        {
            ketemu = 1;
        }
        else
        {
            if (tabInt[k] > cariData)
            {
                j = k - 1;
            }
            else
            {
                i = k + 1;
            }
        }
    }

    if (ketemu == 1)
    {
        printf("[ Data %d terdapat pada kumpulan data ]\n", cariData);
    }
    else
    {
        printf("[ Data %d tidak terdapat pada kumpulan data ]\n", cariData);
    }
}