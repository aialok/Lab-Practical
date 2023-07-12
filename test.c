#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node node;

// Create a new node with the given data
node* createNode(int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Enqueue an element (add to the end of the queue)
void enqueue(node** head, node** tail, int data)
{
    // Create a new node with the given data
    node* newNode = createNode(data);

    // If the queue is empty, set the new node as both head and tail
    if (*head == NULL)
    {
        *head = newNode;
        *tail = *head;
        return;
    }

    // Add the new node at the end of the queue and update the tail
    (*tail)->next = newNode;
    *tail = newNode;
}

// Dequeue an element (remove from the front of the queue)
int dequeue(node** head)
{
    // If the queue is empty, return -1
    if (*head == NULL)
    {   
        printf("queue is underflow");
        return -1;
    }

    // Get the data from the head node
    int item = (*head)->data;

    // Remove the head node and update the head pointer
    node* temp = *head;
    *head = temp->next;
    free(temp);

    // Return the dequeued item
    return item;
}

// Display the elements in the queue
void displayQueue(node* head)
{
    // Traverse the queue and print each element
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    node* head = NULL;
    node* tail = NULL;

    int choice, data;

    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the element to enqueue: \n");
                scanf("%d", &data);
                printf("Enqueued: %d\n", data);
                enqueue(&head, &tail, data);
                break;
            case 2:
                data = dequeue(&head);
                if (data != -1)
                {
                    printf("Dequeued element: %d\n", data);
                }
                break;
            case 3:
                displayQueue(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }

        printf("\n");
    }

    return 0;
}
