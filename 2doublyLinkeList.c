/* Author: Alok Gupta
   CSE(DS & AI)
*/


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node node;

// Function to get the length of the linked list
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

// Function to create a new node
node *createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Operation 1: Insert at the head of the linked list
void insertAtHead(node **head, node **tail, int data)
{
    if (*head == NULL)
    {
        // If the list is empty, create a new head node
        *head = createNode(data);
        *tail = *head;
        return;
    }

    // Create a new node
    node *newNode = createNode(data);

    // Update the links to insert the new node at the head
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

// Operation 2: Insert at the tail of the linked list
void insertAtTail(node **head, node **tail, int data)
{
    if (*head == NULL)
    {
        // If the list is empty, create a new head node
        *head = createNode(data);
        *tail = *head;
        return;
    }

    // Create a new node
    node *newNode = createNode(data);

    // Update the links to insert the new node at the tail
    (*tail)->next = newNode;
    newNode->prev = *tail;
    *tail = newNode;
}

// Operation 3: Delete a node from the linked list
void deleteNode(node **head, node **tail, int data)
{
    if (*head == NULL)
    {
        printf("Empty List\n");
        return;
    }

    // Traverse the linked list to find the node to be deleted
    node *curr = *head;
    node *temp = NULL;
    while (curr->data != data)
    {
        temp = curr;
        curr = curr->next;
    }

    if (curr == *head)
    {
        // If the node to be deleted is the head node
        *head = (*head)->next;
        (*head)->prev = NULL;
        curr->next = NULL;
        curr->prev = NULL;
        free(curr);
        return;
    }

    if (curr == *tail)
    {
        // If the node to be deleted is the tail node
        *tail = temp;
        temp->next = NULL;
        free(curr);
        return;
    }

    // If the node to be deleted is in the middle
    temp->next = curr->next;
    curr->next->prev = temp;
    curr->next = NULL;
    curr->prev = NULL;
    free(curr);
}

// Operation 4: Insert at a specified position in the linked list
void insertAtPosition(node **head, node **tail, int data, int position)
{
    // If the linked list is empty or the position is 0, insert at the head
    if (*head == NULL || position == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }

    // If the position is the last, insert at the tail
    if (position == getLength(*head))
    {
        insertAtTail(head, tail, data);
        return;
    }

    // Insert at the middle
    node *curr = *head;
    for (int i = 0; i < position - 1; i++)
    {
        curr = curr->next;
    }

    // Create a new node and update the links to insert at the specified position
    node *newNode = createNode(data);
    newNode->next = curr->next;
    curr->next->prev = newNode;
    newNode->prev = curr;
    curr->next = newNode;
}

// Operation 5: Print the linked list from the front
void printFront(node *head)
{
    node *curr = head;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    printf("\n");
}

// Operation 6: Print the linked list from the rear
void printRear(node *tail)
{
    node *curr = tail;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->prev;
    }
    printf("\n");
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
        printf("5. Display from Front linked list\n");
        printf("6. Display from Rear linked list\n");
        printf("7. Exit from linked list\n");
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
            printFront(head); // Display the linked list from the front
            break;

        case 6:
            printRear(tail); // Display the linked list from the rear
            break;

        case 7:
            exit(0); // Exit the program
            break;

        default:
            printf("Invalid choice!\n");
            break;
        }
    }
}
