// NAMA : Syahid Nurhidayatullah
// NIM  : 23343056

// Implementasi stack menggunakan linked list prorgram 1

// C program untuk implementasi stack menggunakan array
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// struktur untuk merepresentasikan stack
struct StackNode
{
    int data;
    struct StackNode *next;
};

struct StackNode *newNode(int data)
{
    struct StackNode *stackNode = (struct StackNode *)
        malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(struct StackNode *root)
{
    return !root;
}

void push(struct StackNode **root, int data)
{
    struct StackNode *stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d di push atau ditambahkan ke stack\n", data);
}

int pop(struct StackNode **root)
{
    if (isEmpty(*root))
        return INT_MIN;
    struct StackNode *temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}
int peek(struct StackNode *root)
{
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}
int main()
{
    struct StackNode *root = NULL;
    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
    printf("%d dilepaskan/dihapus dari stack\n", pop(&root));
    printf("Elemen atas (Top) adalah %d\n", peek(root));
    return 0;
}