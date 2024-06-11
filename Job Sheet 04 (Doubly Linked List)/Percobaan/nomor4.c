// NAMA : Syahid Nurhidayatullah
// NIM  : 23343056

// Insertion before given node

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}
/* Given a node as next_node, insert a new node before the given node */

void insertBefore(struct Node **head_ref, struct Node *next_node, int new_data)
{
    /*1. check if the given next_node is NULL */
    if (next_node == NULL)
    {
        printf("the given next node cannot be NULL");
        return;
    }
    /* 2. allocate new node */
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    /* 3. put in the data */
    new_node->data = new_data;
    /* 4. Make prev of new node as prev of next_node */
    new_node->prev = next_node->prev;
    /* 5. Make the prev of next_node as new_node */
    next_node->prev = new_node;
    /* 6. Make next_node as next of new_node */
    new_node->next = next_node;
    /* 7. Change next of new_node's previous node */
    if (new_node->prev != NULL)
        new_node->prev->next = new_node;
    /* 8. If the prev of new_node is NULL, it will be
    the new head node */
    else
        (*head_ref) = new_node;
}
void printList(struct Node *node)
{
    struct Node *last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL)
    {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }
    printf("\nTraversal in reverse direction \n");
    while (last != NULL)
    {
        printf(" %d ", last->data);
        last = last->prev;
    }
}

/* Driver program to test above functions*/
int main()
{
    /* Start with the empty list */
    struct Node *head = NULL;
    push(&head, 7);
    push(&head, 1);
    push(&head, 4);
    insertBefore(&head, head->next, 8);
    printf("Created DLL is: ");
    printList(head);
    getchar();
    return 0;
}