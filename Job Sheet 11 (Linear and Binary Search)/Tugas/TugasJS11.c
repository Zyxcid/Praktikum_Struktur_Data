#include <stdio.h>
#include <string.h>

#define MAX_MAHASISWA 100

typedef struct
{
    int NIM;
    char nama[50];
    char TTL[50];
    float IPK;
} Mahasiswa;

// Fungsi untuk melakukan pencarian sequential
int sequentialSearch(Mahasiswa data[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (data[i].NIM == key)
        {
            return i;
        }
    }
    return -1;
}

// Fungsi untuk melakukan pencarian binary
int binarySearch(Mahasiswa data[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (data[mid].NIM == key)
        {
            return mid;
        }
        else if (data[mid].NIM < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

// Fungsi untuk menampilkan data mahasiswa
void printMahasiswa(Mahasiswa mhs)
{
    printf("NIM: %d\n", mhs.NIM);
    printf("Nama: %s\n", mhs.nama);
    printf("TTL: %s\n", mhs.TTL);
    printf("IPK: %.2f\n", mhs.IPK);
}

int main()
{
    Mahasiswa data[MAX_MAHASISWA];
    int n;

    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &n);

    // Input data mahasiswa
    for (int i = 0; i < n; i++)
    {
        printf("Mahasiswa %d\n", i + 1);
        printf("NIM: ");
        scanf("%d", &data[i].NIM);
        printf("Nama: ");
        scanf(" %[^\n]%*c", data[i].nama);
        printf("TTL: ");
        scanf(" %[^\n]%*c", data[i].TTL);
        printf("IPK: ");
        scanf("%f", &data[i].IPK);
    }

    // Untuk pencarian binary, data harus diurutkan terlebih dahulu
    // Mengurutkan data berdasarkan NIM menggunakan Bubble Sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (data[j].NIM > data[j + 1].NIM)
            {
                Mahasiswa temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    int key;
    printf("Masukkan NIM yang ingin dicari: ");
    scanf("%d", &key);

    // Pencarian sequential
    int indexSeq = sequentialSearch(data, n, key);
    if (indexSeq != -1)
    {
        printf("Data ditemukan dengan sequential search:\n");
        printMahasiswa(data[indexSeq]);
    }
    else
    {
        printf("Data tidak ditemukan dengan sequential search.\n");
    }

    // Pencarian binary
    int indexBin = binarySearch(data, n, key);
    if (indexBin != -1)
    {
        printf("Data ditemukan dengan binary search:\n");
        printMahasiswa(data[indexBin]);
    }
    else
    {
        printf("Data tidak ditemukan dengan binary search.\n");
    }

    return 0;
}
