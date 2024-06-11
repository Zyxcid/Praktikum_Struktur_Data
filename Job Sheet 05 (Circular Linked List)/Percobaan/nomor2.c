// NAMA : Syahid Nurhidayatullah
// NIM  : 23343056

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct doublelinkedlist
{
    int data;
    doublelinkedlist *next, *prev;
} *head, *tail, *current;

void insertlast(int data)
{
    current = (struct doublelinkedlist *)malloc(sizeof(doublelinkedlist));
    current->data = data;
    current->prev = current->next = NULL;
    if (head == NULL)
    {
        head = tail = current;
    }
    else
    {
        current->prev = tail;
        tail->next = current;
        tail = current;
    }
}
void insertfirst(int data)
{
    current = (struct doublelinkedlist *)malloc(sizeof(doublelinkedlist));
    current->data = data;
    current->next = current->prev = NULL;
    if (head == NULL)
    {
        head = tail = current;
    }
    else
    {
        head->prev = current;
        current->next = head;
        head = current;
    }
}
void insertmid(int data)
{
    if (head == NULL)
    {
        insertfirst(data);
    }
    else if (data < head->data)
    {
        insertfirst(data);
    }
    else if (data > tail->data)
    {
        insertlast(data);
    }
    else
    {
        current = (struct doublelinkedlist *)malloc(sizeof(doublelinkedlist));
        current->data = data;
        current->next = current->prev = NULL;
        struct doublelinkedlist *temp = head;
        while (temp != NULL && temp->data < current->data)
        {
            temp = temp->next;
        }
        current->prev = temp->prev;
        current->next = temp;
        temp->prev->next = current;
        temp->prev = current;
    }
}
void deletefirst()
{
    if (head == NULL)
    {
        printf("No Data\n");
    }
    else if (head == tail)
    {
        current = head;
        head = tail = NULL;
        free(current);
    }
    else
    {
        current = head;
        head = head->next;
        head->prev = NULL;
        free(current);
    }
}
void deletelast()
{
    if (head == NULL)
    {
        printf("No Data\n");
    }
    else if (head == tail)
    {
        current = tail;
        head = tail = NULL;
        free(current);
    }
    else
    {
        current = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(current);
    }
}
void deletemid(int data)
{
    int temu = 0;
    if (head == NULL)
    {
        printf("No Data\n");
    }
    else
    {
        current = head;
        while (current != NULL)
        {
            if (current->data == data)
            {
                temu = 1;
                break;
            }
            current = current->next;
        }
        if (temu == 1)
        {
            if (current == head)
            {
                deletefirst();
            }
            else if (current == tail)
            {
                deletelast();
            }
            else
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                free(current);
            }
        }
        else
        {
            printf("Data Not Found\n");
        }
    }
}
void deleteall()
{
    while (head != NULL)
    {
        deletefirst();
    }
}
void print()
{
    current = head;
    if (current != NULL)
    {
        while (current != NULL)
        {
            printf("Data %d\n", current->data);
            current = current->next;
        }
    }
    else
    {
        printf("No Data\n");
    }
}
int main()
{
    insertfirst(2);
    insertfirst(3);
    insertfirst(4);
    insertfirst(5);
    insertlast(6);
    insertmid(7);
    deletemid(7);
    // popMid(6);
    // popAll();
    print();
    getchar();
}