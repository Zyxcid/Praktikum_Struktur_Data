// NAMA : Syahid Nurhidayatullah
// NIM  : 23343056

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack
{
    int top;
    char items[MAX_SIZE];
};

// Fungsi untuk membuat stack kosong
void initializeStack(struct Stack *s)
{
    s->top = -1;
}

// Fungsi untuk mengecek apakah stack kosong
int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

// Fungsi untuk mengecek apakah stack penuh
int isFull(struct Stack *s)
{
    return s->top == MAX_SIZE - 1;
}

// Fungsi untuk menambahkan elemen ke dalam stack
void push(struct Stack *s, char c)
{
    if (isFull(s))
    {
        printf("Stack penuh.\n");
        return;
    }
    s->items[++(s->top)] = c;
}

// Fungsi untuk menghapus elemen dari stack
char pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack kosong.\n");
        return '\0';
    }
    return s->items[(s->top)--];
}

// Fungsi untuk membalik kata dengan menggunakan stack
void reverseWord(char *word)
{
    struct Stack s;
    initializeStack(&s);
    int i;

    // Push setiap karakter ke dalam stack
    for (i = 0; word[i] != '\0'; i++)
    {
        push(&s, word[i]);
    }

    // Pop karakter dari stack untuk mendapatkan kata yang terbalik
    for (i = 0; !isEmpty(&s); i++)
    {
        word[i] = pop(&s);
    }
    word[i] = '\0';
}

int main()
{
    int choice;
    char word[MAX_SIZE];

    do
    {
        printf("\nMenu:\n");
        printf("1. Input Kata\n");
        printf("2. Balik Kata\n");
        printf("3. Exit\n");
        printf("Pilihan Anda: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Masukkan kata: ");
            scanf("%s", word);
            break;
        case 2:
            reverseWord(word);
            printf("Kata setelah dibalik: %s\n", word);
            break;
        case 3:
            printf("Terima kasih!\n");
            break;
        default:
            printf("Pilihan tidak valid.\n");
        }
    } while (choice != 3);

    return 0;
}
