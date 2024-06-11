// NAMA : Syahid Nurhidayatullah
// NIM  : 23343056

// linked list

struct node
{
    int data;
    struct node *next;
};

void push(struct node **head_ref, int new_data) // menambah node pada awal linked list
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insertafter(struct node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void append(struct node **head_ref, int new_data) // fuct menambah node diakhir linked list
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *last = *head_ref;

    new_node->data = new_data;
    new_node->next = *head_ref;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
}

void print(struct node *head)
{
    int i = 0;
    while (i != 5)
    {
        printf(" %d ", head->data);
        head = head->next;
        i++;
    }
}

int main()
{
    struct node *head = NULL;
    append(&head, 0);
    push(&head, 1);
    push(&head, 2);
    // append(&head, 3);
    // insertafter(head->next, 4);

    printf("\n created linked list : ");
    print(head);
    free(head);

    return 0;
}