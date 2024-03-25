// NAMA : Syahid Nurhidayatullah
// NIM  : 23343056

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk menyimpan informasi mobil
typedef struct
{
    char noPlat[15];
    char merk[50];
    char pemilik[100];
} Mobil;

// Struktur untuk simpul dalam linked list
typedef struct Node
{
    Mobil data;
    struct Node *prev;
    struct Node *next;
} Node;

// Fungsi untuk membuat simpul baru
Node *buatSimpul(Mobil data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menambahkan mobil ke akhir antrian
void tambahMobil(Node **head, Mobil data)
{
    Node *newNode = buatSimpul(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Fungsi untuk menghapus mobil berdasarkan nomor plat
void hapusMobil(Node **head, char *noPlat)
{
    Node *current = *head;
    Node *temp = NULL;
    while (current != NULL)
    {
        if (strcmp(current->data.noPlat, noPlat) == 0)
        {
            if (current->prev != NULL)
                current->prev->next = current->next;
            if (current->next != NULL)
                current->next->prev = current->prev;
            temp = current;
            free(temp);
            return;
        }
        current = current->next;
    }
    printf("Mobil dengan nomor plat '%s' tidak ditemukan.\n", noPlat);
}

// Fungsi untuk mencetak semua mobil dalam antrian
void cetakAntrian(Node *head)
{
    printf("Antrian Mobil:\n");
    while (head != NULL)
    {
        printf("Nomor Plat: %s | Merk: %s | Pemilik: %s\n", head->data.noPlat, head->data.merk, head->data.pemilik);
        head = head->next;
    }
}

int main()
{
    Node *head = NULL;

    // Contoh penambahan mobil ke antrian
    Mobil mobil1 = {"B 1234 CD", "Toyota", "John Doe"};
    tambahMobil(&head, mobil1);
    Mobil mobil2 = {"B 5678 EF", "Honda", "Jane Smith"};
    tambahMobil(&head, mobil2);
    Mobil mobil3 = {"B 9876 GH", "BMW", "Michael Johnson"};
    tambahMobil(&head, mobil3);

    // Menampilkan antrian mobil sebelum penghapusan
    cetakAntrian(head);

    // Contoh penghapusan mobil berdasarkan nomor plat
    hapusMobil(&head, "B 5678 EF");

    // Menampilkan antrian mobil setelah penghapusan
    cetakAntrian(head);

    return 0;
}
