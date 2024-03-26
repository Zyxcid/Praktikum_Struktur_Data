// NAMA : Syahid Nurhidayatullah
// NIM  : 23343056

// Reversing Stack Menggunakan Recursion

// C Program untuk membalikkan stack menggunakan rekursi
#include <stdio.h>
#include <stdlib.h>
#define bool int
// Struktur node dari Stack
struct sNode
{
    char data;
    struct sNode *next;
};

// Fungsi Prototype
void push(struct sNode **top_ref, int new_data);
int pop(struct sNode **top_ref);
bool isEmpty(struct sNode *top);
void print(struct sNode *top);

// Di bawah ini adalah fungsi rekursif
// yang menyisipkan elemen
// di bagian bawah stack.

void insertAtBottom(struct sNode **top_ref, int item)
{
    if (isEmpty(*top_ref))
        push(top_ref, item);
    else
    {
        // Menahan semua item di Fungsi Call Stack hingga mencapai ujung Stack.
        // Ketika stack menjadi kosong, isEmpty(*top_ref)menjadi True
        // bagian if di atas dijalankan dan item disisipkan di bagian bawah
        int temp = pop(top_ref);
        insertAtBottom(top_ref, item);
        // Setelah item ditambahkan di bagian bawah
        // dorong semua item yang disimpan di Fungsi Call Stack
        push(top_ref, temp);
    }
}
// Di bawah ini adalah fungsi yang membalikkan stack yang diberikan
// menggunakan insertAtBottom()
void reverse(struct sNode **top_ref)
{
    if (!isEmpty(*top_ref))
    {
        // Menahan semua item di Fungsi Call Stack
        // hingga akhir stack dicapai
        int temp = pop(top_ref);
        reverse(top_ref);
        // Memasukan semua item (ditahan di Function Call Stack) satu per satu
        // dari bawah ke atas. Setiap item dimasukkan di bagian bawah
        insertAtBottom(top_ref, temp);
    }
}
// Driver Code
int main()
{
    struct sNode *s = NULL;
    push(&s, 4);
    push(&s, 3);
    push(&s, 2);
    push(&s, 1);
    printf("\n Stack Awal ");
    print(s);
    reverse(&s);
    printf("\n Stack yang dibalikkan ");
    print(s);
    return 0;
}
// Fungsi untuk mengecek apakah Stack kosong
bool isEmpty(struct sNode *top)
{
    return (top == NULL) ? 1 : 0;
}
// Fungsi untuk menambahkan item ke stack
void push(struct sNode **top_ref, int new_data)
{
    // mengalokasikan node
    struct sNode *new_node = (struct sNode *)malloc(sizeof(struct sNode));
    if (new_node == NULL)
    {
        printf("Stack overflow \n");
        exit(0);
    }
    // Memasukan kedalam data
    new_node->data = new_data;
    // Menautkan list lama dari node baru
    new_node->next = (*top_ref);
    // Menggerakan head untuk menunjuk (point) ke node baru
    (*top_ref) = new_node;
}
// Fungsi untuk mengeluarkan item dari stack
int pop(struct sNode **top_ref)
{
    char res;
    struct sNode *top;
    // jika Stack kosong, maka error
    if (*top_ref == NULL)
    {
        printf("Stack overflow \n");
        exit(0);
    }
    else
    {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;
    }
}
// Fungsi untuk menampilkan linked list
void print(struct sNode *top)
{
    printf("\n");
    while (top != NULL)
    {
        printf(" %d ", top->data);
        top = top->next;
    }
}