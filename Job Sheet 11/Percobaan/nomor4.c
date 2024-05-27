#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tabInt[10] = {25, 1, 22, 15, 13, 54, 13, 21, 99, 67};
    int ketemu;
    int cariData;
    int i;

    system("cls");
    printf("Masukkan data yang dicari = ");
    scanf("%d", &cariData);

    i = 0;
    ketemu = 0;
    while (i < 10 && ketemu != 1)
    {
        if (tabInt[i] == cariData)
        {
            ketemu = 1;
        }
        else
        {
            i++;
        }
    }
    if (ketemu == 1)
    {
        printf("\n[ Data %d terdapat pada kumpulan data ]\n", cariData);
    }
    else
    {
        printf("\n[ Data %d tidak terdapat pada kumpulan data ]\n", cariData);
    }
    return 0;
}