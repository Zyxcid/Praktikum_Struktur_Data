// NAMA : Syahid Nurhidayatullah
// NIM  : 23343056

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk menyimpan informasi buku
typedef struct
{
    char judul[100];
    char pengarang[100];
    int tahun;
} Buku;

// Struktur untuk simpul dalam linked list
typedef struct Node
{
    Buku data;
    struct Node *prev;
    struct Node *next;
} Node;

// Fungsi untuk membuat simpul baru
Node *buatSimpul(Buku data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menambahkan simpul baru ke linked list di akhir
void tambahDiAkhir(Node **head, Buku data)
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

// Fungsi untuk menghapus simpul berdasarkan judul buku
void hapusBerdasarkanJudul(Node **head, char *judul)
{
    Node *current = *head;
    Node *temp = NULL;
    while (current != NULL)
    {
        if (strcmp(current->data.judul, judul) == 0)
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
    printf("Buku dengan judul '%s' tidak ditemukan.\n", judul);
}

// Fungsi untuk mencetak semua buku dalam linked list
void cetakList(Node *head)
{
    printf("Daftar Buku:\n");
    while (head != NULL)
    {
        printf("Judul: %s | Pengarang: %s | Tahun: %d\n", head->data.judul, head->data.pengarang, head->data.tahun);
        head = head->next;
    }
}

int main()
{
    Node *head = NULL;

    // Contoh penambahan buku
    Buku buku1 = {"Harry Potter", "J.K. Rowling", 1997};
    tambahDiAkhir(&head, buku1);
    Buku buku2 = {"Lord of the Rings", "J.R.R. Tolkien", 1954};
    tambahDiAkhir(&head, buku2);
    Buku buku3 = {"Pride and Prejudice", "Jane Austen", 1813};
    tambahDiAkhir(&head, buku3);

    // Menampilkan daftar buku sebelum penghapusan
    cetakList(head);

    // Contoh penghapusan buku berdasarkan judul
    hapusBerdasarkanJudul(&head, "Lord of the Rings");

    // Menampilkan daftar buku setelah penghapusan
    cetakList(head);

    return 0;
}
