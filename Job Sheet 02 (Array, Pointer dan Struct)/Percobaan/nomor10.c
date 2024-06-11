// NAMA : Syahid Nurhidayatullah
// NIM  : 23343056

// ADT

#include <stdio.h>
typedef struct
{
    int HH, MM, SS;
} jam;
void tampil(jam j)
{
    printf("JAM %d:%d:%d\n", j.HH, j.MM, j.SS);
}
int valid(jam j)
{
    return j.HH >= 0 && j.HH <= 23 &&
           j.MM >= 0 && j.MM <= 59 &&
           j.SS >= 0 && j.SS <= 59;
}

jam input()
{
    jam j;
    do
    {
        printf("Masukkan Jam = ");
        scanf("%d", &j.HH);
        printf("Masukkan Menit = ");
        scanf("%d", &j.MM);
        printf("Masukkan Second = ");
        scanf("%d", &j.SS);
    } while (!valid(j));
    return j;
}
int main()
{
    jam j;
    j = input();
    tampil(j);
    return 0;
}