// NAMA : Syahid Nurhidayatullah
// NIM  : 23343056

// Insertion at front

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void push(struct Node **head_ref, int new_data)
{
    // 1.allocate node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    // 2.Put in the data
    new_node->data = new_data;

    // 3.Make next of new node as head and previous NULL;
    new_node->prev = (*head_ref);
    new_node->next = NULL;

    // 4.change prev of head node to new node
    if ((*head_ref) != NULL)
    {
        (*head_ref)->next = new_node;
    }

    // 5.Move the head to point the new node
    (*head_ref) = new_node;
}

void printlist(struct Node *node)
{
    struct Node *last;
    printf("\n Traversal in forward direction \n");
    while (node != NULL)
    {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }

    printf("\n Traversal in reverse direction \n");
    while (last != NULL)
    {
        printf(" %d ", last->data);
        last = last->prev;
    }
}

int main()
{
    // start with an empty list
    struct Node *head = NULL;
    push(&head, 6);
    push(&head, 5);
    push(&head, 2);
    printf("created DLL are:");
    printlist(head);
    getchar();
    return 0;
}
