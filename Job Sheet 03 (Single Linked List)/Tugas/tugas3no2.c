// NAMA : Syahid Nurhidayatullah
// NIM  : 23343056

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Fungsi untuk mengecek apakah suatu bilangan adalah prima
bool isPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

// Fungsi untuk mencetak bilangan prima pertama sampai ke-n
void printPrimes(int n)
{
    // Mengalokasikan memori awal
    int *primes = (int *)malloc(n * sizeof(int));
    if (primes == NULL)
    {
        printf("Alokasi memori gagal!");
        exit(1);
    }

    int count = 0; // Counter untuk jumlah bilangan prima yang telah ditemukan
    int num = 2;   // Bilangan yang akan dicek keprimaannya

    // Melakukan iterasi hingga menemukan n bilangan prima
    while (count < n)
    {
        if (isPrime(num))
        {
            primes[count] = num;
            count++;

            // Melakukan realokasi memori jika diperlukan
            primes = (int *)realloc(primes, count * sizeof(int));
            if (primes == NULL)
            {
                printf("Realokasi memori gagal!");
                exit(1);
            }
        }
        num++;
    }

    // Menampilkan bilangan prima
    printf("Bilangan prima pertama sampai ke-%d adalah:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", primes[i]);
    }
    printf("\n");

    // Membebaskan memori yang dialokasikan
    free(primes);
}

int main()
{
    int n, m;

    // Input jumlah bilangan prima yang ingin ditampilkan
    printf("Masukkan jumlah bilangan prima yang ingin ditampilkan: ");
    scanf("%d", &n);

    // Input ukuran memori baru
    printf("Masukkan ukuran memori baru (m): ");
    scanf("%d", &m);

    // Memanggil fungsi printPrimes
    printPrimes(n);

    return 0;
}
