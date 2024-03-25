// NAMA : Syahid Nurhidayatullah
// NIM  : 23343056

// Membuat Program Single Linked List

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *create_linked_list(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_node(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *sort_list(struct node *);
int main(int argc, char *argv[])
{
    int option;

    do
    {
        printf("\n\n ======= SINGLE LINKED LIST =======\n");
        printf("\n 1: Buat Single Linked List");
        printf("\n 2: Tampilkan semua node Single Linked List");
        printf("\n 3: Tambah node di awal Single Linked List");
        printf("\n 4: Tambah node di akhir Single Linked List");
        printf("\n 5: Tambah node sebelum node yang diberikan");
        printf("\n 6: Tambah node setelah node yang diberikan");
        printf("\n 7: Hapus node di awal Single Linked List");
        printf("\n 8: Hapus node di akhir Single Linked List");
        printf("\n 9: Hapus sebuah node tertentu");
        printf("\n 10: Hapus node setelah node yang diberikan");
        printf("\n 11: Hapus semua node Single Linked List");
        printf("\n 12: Urutkan data Single Linked List");
        printf("\n 13: Keluar dari Program");
        printf("\n\n Masukan pilihan menu : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            system("cls");
            start = create_linked_list(start);
            printf("\n LINKED LIST CREATED");
            break;

        case 2:
            system("cls");
            start = display(start);
            break;

        case 3:
            system("cls");
            start = insert_beg(start);
            break;

        case 4:
            system("cls");
            start = insert_end(start);
            break;

        case 5:
            system("cls");
            start = insert_before(start);
            break;
        case 6:
            system("cls");
            start = insert_after(start);
            break;
        case 7:
            system("cls");
            start = delete_beg(start);
            break;
        case 8:
            system("cls");
            start = delete_end(start);
            break;
        case 9:
            system("cls");
            start = delete_node(start);
            break;
        case 10:
            system("cls");
            start = delete_after(start);
            break;
        case 11:
            start = delete_list(start);
            printf("\n LINKED LIST DELETED");
            break;
        case 12:
            start = sort_list(start);
            break;
        }
    } while (option != 13);
    getch();
    return 0;
}

struct node *create_linked_list(struct node *start)
{
    system("cls");
    struct node *new_node, *ptr;
    int num;
    printf("\n Tekan 0 untuk berhenti input data");
    printf("\n Masukan data : ");
    scanf("%d", &num);
    while (num != 0)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if (start == NULL)
        {
            new_node->next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->next = NULL;
        }
        printf(" Masukan data berikutnya : ");
        scanf("%d",
              &num);
    }
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    printf(" DATA SINGLE LINKED LIST \n\n");
    while (ptr != NULL)
    {
        printf("\t %d", ptr->data);
        ptr = ptr->next;
    }
    return start;
}
struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;
    printf(" TAMBAH DATA DI AWAL \n\n");
    printf("\n Masukan data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = start;
    start = new_node;
    printf("\n DATA BERHASIL DITAMBAHKAN! \n");
    return start;
}
struct node *insert_end(struct node *start)
{
    struct node *ptr, *new_node;
    int num;
    printf(" TAMBAH DATA DI AKHIR \n\n");
    printf("\n Masukan data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = new_node;
    new_node->next = NULL;
    printf("\n DATA BERHASIL DITAMBAHKAN! \n");
    return start;
}

struct node *insert_before(struct node *start)
{
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf(" TAMBAH DATA SEBELUM NODE TERTENTU \n\n");
    printf("\n Masukan data : ");
    scanf("%d", &num);
    printf("\n Data baru ditambahkan sebelum node dengan data : ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    while (ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    printf("\n DATA BERHASIL DITAMBAHKAN! \n");
    return start;
}

struct node *insert_after(struct node *start)
{
    struct node *new_node, *ptr, *preptr;
    int num, val;
    printf(" TAMBAH DATA SETELAH NODE TERTENTU \n\n");
    printf("\n Masukan data : ");
    scanf("%d", &num);
    printf("\n Data baru ditambahkan setelah node dengan data : ");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    preptr = ptr;
    while (preptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = new_node;
    new_node->next = ptr;
    printf("\n DATA BERHASIL DITAMBAHKAN! \n");
    return start;
}

struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    printf("\n DATA AWAL BERHASIL DIHAPUS! \n");
    return start;
}
struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;
    ptr = start;
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    printf("\n DATA AKHIR BERHASIL DIHAPUS! \n");
    return start;
}
struct node *delete_node(struct node *start)
{
    struct node *ptr, *preptr;
    int val;
    printf("\n HAPUS DATA TERTENTU SINGLE LINKED LIST \n");
    printf("\n Masukan data node yang ingin dihapus : ");
    scanf("%d", &val);
    ptr = start;
    if (ptr->data == val)
    {
        start = delete_beg(start);
        return start;
    }
    else
    {
        while (ptr->data != val)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        printf("\n DATA BERHASIL DIHAPUS! \n");
        return start;
    }
}
struct node *delete_after(struct node *start)
{
    struct node *ptr, *preptr;
    int val;
    printf("\n HAPUS DATA AWAL SINGLE LINKED LIST \n");
    printf("\n Masukan data setelah node yang akan dihapus : ");
    scanf("%d", &val);
    ptr = start;
    while (ptr->data != val)
        ptr = ptr->next;
    preptr = ptr->next;
    ptr->next = preptr->next;
    preptr->next = ptr;
    free(preptr);
    printf("\n DATA BERHASIL DIHAPUS! \n");
    return start;
}
struct node *delete_list(struct node *start)
{
    struct node *ptr;
    if (start != NULL)
    {
        ptr = start;
        while (ptr != NULL)
        {
            printf("\n %d is to be deleted next", ptr->data);
            start = delete_beg(ptr);
            ptr = start;
        }
    }
    return start;
}

struct node *sort_list(struct node *start)
{
    printf("\n DATA SINGLE LINKED LIST SUDAH TERURUT DARI K > B!\n");
    struct node *ptr1, *ptr2;
    int temp;
    ptr1 = start;
    while (ptr1->next != NULL)
    {
        ptr2 = ptr1->next;
        while (ptr2 != NULL)
        {
            if (ptr1->data > ptr2->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }

    return start;
}