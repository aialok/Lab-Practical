#include <stdio.h>
#include <stdlib.h>



// Function prototypes
void printCurrentLevel(node* root, int level);
int height(node* node);
node* newNode(int data);
 








struct node
{
    int data;
    struct node *right;
    struct node *left;
};

typedef struct node node;

node* createNode(int data)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}
void insert(node **root)
{
    printf("Enter the data you want to put in the tree:\n");
    int data;
    scanf("%d", &data);

    if (data == -1)
    {
        return;
    }

    if (*root == NULL)
    {
        *root = createNode(data);
    }

    printf("Enter data for inserting in the left of %d:\n", data);
    insert(&((*root)->left));

    printf("Enter the data for inserting in the right of %d:\n", data);
    insert(&((*root)->right));
}

void inorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(node*root)
{
    if(root==NULL)
    {
        return;
    }

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);


}

void postorderTraversal(node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}


int main()
{
    node *root = NULL;

    insert(&root);
    printf("Inorder Traversal\n");
    inorderTraversal(root);
    printf("\n");
    printf("Preorder Traversal\n");
    preorderTraversal(root);
     printf("\n");
    printf("PostOrder Traversal\n");
    postorderTraversal(root);
}