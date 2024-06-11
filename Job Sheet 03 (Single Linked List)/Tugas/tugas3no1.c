// NAMA : Syahid Nurhidayatullah
// NIM  : 23343056

#include <stdio.h>
#include <stdlib.h>

// Fungsi untuk menghitung bilangan Fibonacci ke-n
int *fibonacci(int n)
{
    // Mengalokasikan memori untuk menyimpan bilangan Fibonacci
    int *fib = (int *)malloc(n * sizeof(int));

    // Pengecekan apakah alokasi memori berhasil
    if (fib == NULL)
    {
        printf("Alokasi memori gagal!");
        exit(1);
    }

    // Mengisi bilangan Fibonacci pertama dan kedua
    fib[0] = 0;
    fib[1] = 1;

    // Menghitung dan menyimpan bilangan Fibonacci ke-n
    for (int i = 2; i < n; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    // Mengembalikan pointer ke array bilangan Fibonacci
    return fib;
}

int main()
{
    int n;

    // Input jumlah bilangan Fibonacci yang ingin ditampilkan
    printf("Masukkan jumlah bilangan Fibonacci yang ingin ditampilkan: ");
    scanf("%d", &n);

    // Memanggil fungsi Fibonacci untuk menghitung bilangan Fibonacci
    int *fib = fibonacci(n);

    // Menampilkan bilangan Fibonacci
    printf("Bilangan Fibonacci pertama sampai ke-%d adalah:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", fib[i]);
    }
    printf("\n");

    // Membebaskan memori yang dialokasikan
    free(fib);

    return 0;
}
