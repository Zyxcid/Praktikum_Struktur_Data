#include <stdio.h>
#include <stdlib.h>

// structure of the node
struct Node
{
	int data;
	struct Node *next; // Pointer to next node
	struct Node *prev; // Pointer to previous node
};

void insertEnd(struct Node **start, int value)
{
	// if the list is empty, create a single node
	// circular and doubly linked list
	if (*start == NULL)
	{
		struct Node *new_node = new Node;
		new_node->data = value;
		new_node->next = new_node->prev = new_node;
		*start = new_node;
		return;
	}
	else
	{
		// if list is not empty, Find last node
		struct Node *last = (*start)->prev;
		// Create node dynamically
		struct Node *new_node = new Node;
		new_node->data = value;
		last->next = new_node;	   // make new_node next of old last
		new_node->prev = last;	   // make last previous of new_node
		new_node->next = (*start); // start is going to be the next of new_node
		(*start)->prev = new_node; // make new_node previous of start
	}
}

void display(struct Node *start)
{
	struct Node *temp = start;
	printf("\nTraversal in forward direction \n");
	while (temp->next != start)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("%d ", temp->data);
	printf("\nTraversal in reverse direction \n");
	struct Node *last = start->prev;
	while (temp->prev != last)
	{
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("%d", temp->data);
}

int main()
{
	// start with the empty list
	struct Node *start = NULL;
	// insert 5. so linked list becomes 5->NULL
	insertEnd(&start, 5);
	insertEnd(&start, 8);
	insertEnd(&start, 9);
	insertEnd(&start, 3);
	printf("Created circular doubly linked list is : ");
	display(start);
	return 0;
}
