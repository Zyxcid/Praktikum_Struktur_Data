// NAMA : Syahid Nurhidayatullah
// NIM  : 23343056

// ARRAY
#include <stdio.h>

int main()
{
    int n;
    int angka[100];

    printf("Masukkan banyaknya bilangan: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Masukkan angka ke %d ", i + 1);

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &angka[i]);
        }

        for (int i = 0; i < n; i++)
        {
            printf("Angka ke %d : %d\n", i + 1, angka[i]);
        }
    }

    getchar();
    return 0;
}