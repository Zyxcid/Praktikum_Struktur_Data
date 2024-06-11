// NAMA : Syahid Nurhidayatullah
// NIM  : 23343056

#include <stdio.h>
#include <stdlib.h>

// Mendefinisikan struktur Mahasiswa
struct Mahasiswa
{
    char NIM[15];
    char Nama[50];
    char tanggalLahir[20];
    float IPK;
};

// Fungsi untuk input data mahasiswa
void inputDataMahasiswa(struct Mahasiswa *mahasiswa)
{
    printf("Masukkan NIM: ");
    scanf("%s", mahasiswa->NIM);

    printf("Masukkan Nama: ");
    scanf(" %[^\n]s", mahasiswa->Nama); // Menggunakan " %[^\n]s" untuk menerima input string dengan spasi

    printf("Masukkan Tanggal Lahir (DD/MM/YYYY): ");
    scanf("%s", mahasiswa->tanggalLahir);

    printf("Masukkan IPK: ");
    scanf("%f", &mahasiswa->IPK);
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanDataMahasiswa(struct Mahasiswa *mahasiswa)
{
    printf("\nData Mahasiswa:\n");
    printf("NIM: %s\n", mahasiswa->NIM);
    printf("Nama: %s\n", mahasiswa->Nama);
    printf("Tanggal Lahir: %s\n", mahasiswa->tanggalLahir);
    printf("IPK: %.2f\n", mahasiswa->IPK);
}

int main()
{
    // Deklarasi variabel bertipe Mahasiswa
    struct Mahasiswa mhs;

    // Memanggil fungsi untuk input data mahasiswa
    inputDataMahasiswa(&mhs);

    // Memanggil fungsi untuk menampilkan data mahasiswa
    tampilkanDataMahasiswa(&mhs);

    return 0;
}