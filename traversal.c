#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

struct Queue {
    int front;
    int rear;
    int size;
    struct TreeNode* array[MAX_QUEUE_SIZE];
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}
 
int isQueueEmpty(struct Queue* queue) {
    return queue->size == 0;
}

int isQueueFull(struct Queue* queue) {
    return queue->size == MAX_QUEUE_SIZE;
}

void enqueue(struct Queue* queue, struct TreeNode* item) {
    if (isQueueFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    
    if (isQueueEmpty(queue)) {
        queue->front = 0;
    }
    
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->array[queue->rear] = item;
    queue->size++;
}

struct TreeNode* dequeue(struct Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return NULL;
    }

    struct TreeNode* item = queue->array[queue->front];
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    queue->size--;

    return item;
}

struct node {
    int data;
    struct node* right;
    struct node* left;
};

typedef struct node node;

node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

void insert(node** root) {
    printf("Enter the data you want to put in the tree:\n");
    int data;
    scanf("%d", &data);

    if (data == -1) {
        return;
    }

    if (*root == NULL) {
        *root = createNode(data);
    }

    printf("Enter data for inserting in the left of %d:\n", data);
    insert(&((*root)->left));

    printf("Enter the data for inserting in the right of %d:\n", data);
    insert(&((*root)->right));
}

void levelOrderTraversal(node* root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    struct Queue* queue = createQueue();
    enqueue(queue, root);
    enqueue(queue, NULL);  // Separator between levels

    while (!isQueueEmpty(queue)) {
        node* current = dequeue(queue);

        if (current == NULL) {
            printf("\n");  // Level separator reached
            if (!isQueueEmpty(queue)) {
                enqueue(queue, NULL);  // Add separator for the next level
            }
        } else {
            printf("%d ", current->data);

            if (current->left != NULL) {
                enqueue(queue, current->left);
            }
            if (current->right != NULL) {
                enqueue(queue, current->right);
            }
        }
    }
}

int main() {
    node* root = NULL;
    insert(&root);
    levelOrderTraversal(root);

    return 0;
}
