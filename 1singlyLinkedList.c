/* Author: Alok Gupta
   CSE(DS & AI)
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

// Function to create a new node
node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the head of the linked list
void insertAtHead(node **head, node **tail, int data)
{
    if (*head == NULL)
    {
        // If the list is empty, create a new node and set it as both head and tail
        *head = createNode(data);
        *tail = *head;
        return;
    }

    // Create a new node and make it the new head
    node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the tail of the linked list
void insertAtTail(node **head, node **tail, int data)
{
    if (*head == NULL)
    {
        // If the list is empty, create a new node and set it as both head and tail
        *head = createNode(data);
        *tail = *head;
        return;
    }

    // Create a new node and make it the next node of the current tail
    node *newNode = createNode(data);
    (*tail)->next = newNode;
    *tail = newNode;
}
// Function to getLength in linkedlist
int getLength(node *head)
{
    int count = 0;
    node *curr = head;
    while (curr != NULL)
    {
        count += 1;
        curr = curr->next;
    }
    return count;
}

// Function to insert at any position
void insertAtPosition(node **head, node **tail, int data, int position)
{
    // LinkedList is empty or position is 0
    if (*head == NULL || position == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }

    // If position is last
    if (position == getLength(*head))
    {
        insertAtTail(head, tail, data);
        return;
    }

    // Insert at middle
    node *curr = *head;
    for (int i = 0; i < position - 1; i++)
    {
        curr = curr->next;
    }

    node *newNode = createNode(data);

    newNode->next = curr->next;
    curr->next = newNode;
}

// Function to print the linked list
void printLL(node *head)
{
    printf("Hello\n");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

// Function to delete a node from the linked list based on a given value
void deleteNode(node **head, node **tail, int value)
{
    node *curr = *head;
    node *prev = NULL;

    // Find the node with the given value
    while (curr != NULL && curr->data != value)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL)
    {
        // If the value is not found in the list
        printf("Invalid Value\n");
        return;
    }

    if (curr == *head)
    {
        // If the node to be deleted is the head node
        *head = curr->next;
    }
    else
    {
        // If the node to be deleted is in the middle or tail
        prev->next = curr->next;
    }

    if (curr == *tail)
    {
        // If the node to be deleted is the tail node, update the tail pointer
        *tail = prev;
    }

    free(curr); // Free the memory occupied by the deleted node
}

int main()
{
    node *head = NULL;
    node *tail = head;
    while (1)
    {
        int choice;
        printf("Choose an operation:\n");
        printf("1. Insert at head\n");
        printf("2. Insert at tail\n");
        printf("3. Insert at middle\n");
        printf("4. Delete node\n");
        printf("5. Display linked list\n");
        scanf("%d", &choice);

        int position, data;
        switch (choice)
        {
        case 1:
            printf("Enter data to insert at head: ");
            scanf("%d", &data);
            insertAtHead(&head, &tail, data);
            break;

        case 2:
            printf("Enter data to insert at tail: ");
            scanf("%d", &data);
            insertAtTail(&head, &tail, data);
            break;

        case 3:
            printf("Enter position to insert at middle: ");
            scanf("%d", &position);
            printf("Enter data to insert at middle: ");
            scanf("%d", &data);
            insertAtPosition(&head, &tail, data, position);
            break;

        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &data);
            deleteNode(&head, &tail, data);
            break;

        case 5:
            printLL(head); // Display the linked list
            break;

        default:
            printf("Invalid choice!\n");
            break;
        }
    }
    return 0;
}
