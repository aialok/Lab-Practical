#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

typedef struct node node;

node* createNode(int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enqueue(node** head, node** tail, int data)
{
    node* newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        *tail = *head;
        return;
    }

    (*tail)->next = newNode;
    *tail = newNode;
}

int dequeue(node** head)
{
    if (*head == NULL)
    {
        return -1;
    }

    int item = (*head)->data;
    node* temp = *head;
    *head = temp->next;

    free(temp);

    return item;
}

void displayQueue(node* head)
{
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
                printf("Enqueued: %d: \n", data);
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
