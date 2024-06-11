// NAMA : Syahid Nurhidayatullah
// NIM  : 23343056

// Structure (ADT)

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nama[25];
    int nik;
    char alamat[30];
    char status[25];
} ktp;

int main()
{
    ktp myktp;
    printf("Nama\t: ");
    gets(myktp.nama);
    fflush(stdin);
    printf("NIK \t: ");
    scanf("%i", &myktp.nik);
    fflush(stdin);
    printf("Alamat\t: ");
    gets(myktp.alamat);
    printf("Kewarganegaraan\t: ");
    gets(myktp.status);

    return 0;
}