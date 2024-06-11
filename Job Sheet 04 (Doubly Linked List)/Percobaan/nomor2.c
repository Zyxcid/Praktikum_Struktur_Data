// NAMA : Syahid Nurhidayatullah
// NIM  : 23343056

// Penambahan setelah simpul yang ditentukan

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

void insertafter(struct Node *prev_node, int new_data)
{
    // 1.check if the given prev node is NULL
    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }

    // 2.allocate new node
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    // 3.Put in the data
    new_node->data = new_data;

    // 4.make next of new node as next of prev node
    new_node->next = prev_node->next;

    // 5.make next of prev node as new_node
    prev_node->next = new_node;

    // 6.Make prev node as previous of new_node
    new_node->prev = prev_node;

    // 7.change previous of new_node's next node
    if (new_node->next != NULL)
    {
        new_node->next->prev = new_node;
    }
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
    insertafter(head->prev, 3);
    printf("created DLL are:");
    printlist(head);
    getchar();
    return 0;
}
