// NAMA : Syahid Nurhidayatullah
// NIM  : 23343056

// Insertion at Beginning

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void print(struct node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}
int main()
{
    struct node *head = NULL;
    struct node *second = NULL;
    struct node *third = NULL;
    struct node *new_node = NULL;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    new_node = (struct node *)malloc(sizeof(struct node));

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    new_node->data = 4;
    new_node->next = head;
    head = new_node;

    print(head);
    return 0;
}