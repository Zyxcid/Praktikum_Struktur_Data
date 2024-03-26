// NAMA : Syahid Nurhidayatullah
// NIM  : 23343056

// Implementasi stack menggunakan array prorgram 2

#include <stdio.h>
#include <stdlib.h>

#define UKURAN 5

void push(int);
void pop();
void display();

int stack[UKURAN], atas = -1;

int main()
{
    int value, pilihan;
    while (1)
    {
        printf("\n\n***** MENU *****\n");
        printf("1. Push\n2. Pop\n3. Tampilkan\n4. Keluar");
        printf("\nMasukan pilihanmu: ");
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 1:
            printf("Masukan value yang ingin dimasukan: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("\nPilihan tidak valid! silakan coba lagi!");
        }
    }
}

void push(int value)
{
    if (atas == UKURAN - 1)
        printf("\nStack telah penuh, Tidak memungkinkan menambah item");
    else
    {
        atas++;
        stack[atas] = value;
        printf("\nItem berhasil ditambahkan");
    }
}

void pop()
{
    if (atas == -1)
        printf("\nStack kosong, tidak memungkinkan untuk menghapus item");
    else
    {
        printf("\nItem berhasil dihapus: %d", stack[atas]);
        atas--;
    }
}
void display()
{
    if (atas == -1)
        printf("\nStack kosong. Tidak ada item yang bisa ditampilkan");
    else
    {
        int i;
        printf("\nItem yang ada pada stack adalah:\n");
        for (i = atas; i >= 0; i--)
            printf("%d\n", stack[i]);
    }
}