// NAMA : Syahid Nurhidayatullah
// NIM  : 23343056

// Circular Singly Linked List

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head;
void tambahAwal();
void tambahAkhir();
void hapusAwal();
void hapusAkhir();
void tampilkan();
void cari();
int main()
{
    int choice = 0;
    while (choice != 7)
    {
        printf("\n*********Main Menu*********\n");
 printf("\nSilakan pilih salah satu dari menu berikut 
...\n"); 
 
printf("\n===============================================\n");
printf("\n1.Masukan data di awal\n2.Masukan data di 
akhir\n3.Hapus dari awal\n4.Hapus dari akhir\n5.Cari sebuah 
elemen\n6.Tampilkan\n7.Exit\n"); 
 printf("\nMasukan pilihanmu? \n"); 
 scanf("\n%d",&choice); 
 switch(choice) {
        case 1:
            tambahAwal();
            break;
        case 2:
            tambahAkhir();
            break;
        case 3:
            hapusAwal();
            break;
        case 4:
            hapusAkhir();
            break;
        case 5:
            cari();
            break;
        case 6:
            tampilkan();
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Mohon masukan pilihan yang sesuai menu.."); 
 }
    }
}
void tambahAwal()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nMasukan node data? ");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
                temp = temp->next;
            ptr->next = head;
            temp->next = ptr;
            head = ptr;
        }
        printf("\nnode telah dimasukan\n");
    }
}
void tambahAkhir()
{
    struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
    }
    else
    {
        printf("\nMasukan data? ");
        scanf("%d", &item);
        ptr->data = item;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->next = head;
        }
        printf("\nnode inserted\n");
    }
}

void hapusAwal()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        printf("\nnode dihapus\n");
    }

    else
    {
        ptr = head;
        while (ptr->next != head)
            ptr = ptr->next;
        ptr->next = head->next;
        free(head);
        head = ptr->next;
        printf("\nnode dihapus\n");
    }
}
void hapusAkhir()
{
    struct node *ptr, *preptr;
    if (head == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if (head->next == head)
    {
        head = NULL;
        free(head);
        printf("\nnode dihapus\n");
    }
    else
    {
        ptr = head;
        while (ptr->next != head)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        printf("\nnode dihapus\n");
    }
}

void cari()
{
    struct node *ptr;
    int item, i = 0, flag = 1;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\nList Kosong\n");
    }
    else
    {
        printf("\nMasukan item yang ingin dicari?\n");
        scanf("%d", &item);
        if (head->data == item)
        {
            printf("item ditemukan pada lokasi %d", i + 1);
            flag = 0;
        }
        else
        {
            while (ptr->next != head)
            {
                if (ptr->data == item)
                {
                    printf("item ditemukan pada lokasi %d ", i + 1);
                    flag = 0;
                    break;
                }
                else
                {
                    flag = 1;
                }
                i++;
                ptr = ptr->next;
            }
        }
        if (flag != 0)
        {
            printf("Item tidak ditemukan\n");
        }
    }
}

void tampilkan()
{
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("\ntidak ada sesuatu untuk ditampilkan");
    }
    else
    {
        printf("\n Menampilkan nilai... \n");
        while (ptr->next != head)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n", ptr->data);
    }
}