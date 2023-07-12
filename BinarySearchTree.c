/*Author: Alok Gupta
  CSE(DS & AI)
  @ai.alok
*/

// Binary Search Tree

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node node;

// Create a new node with the given data
node *createNode(int data)
{
    // Allocate memory for the new node
    node *newNode = (node *)malloc(sizeof(struct node));

    // Set the data and initialize left and right pointers to NULL
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    // Return the newly created node
    return newNode;
}

// Build a binary search tree by inserting data into the tree recursively
node *buildTree(node *root, int data)
{
    if (root == NULL)
    {
        // If the root is NULL, create a new node and assign it as the root
        root = createNode(data);
        return root;
    }

    if (data > root->data)
    {
        // If the data is greater than the current node's data, insert it into the right subtree
        root->right = buildTree(root->right, data);
    }
    else if (data < root->data)
    {
        // If the data is less than the current node's data, insert it into the left subtree
        root->left = buildTree(root->left, data);
    }

    return root;
}

// Take user input to build the binary search tree
void takeInput(node **root)
{
    printf("Enter the data to insert in the main root\n");
    int data;
    scanf("%d", &data);
    printf("Data entered in the root node is: %d\n", data);

    while (data != -1)
    {
        // Build the binary search tree by inserting data
        *root = buildTree(*root, data);
        scanf("%d", &data);
    }
}

// Find the minimum value in a binary search tree
int minValBST(node *root)
{
    // Create a temporary node and initialize it with the root
    node *temp = root;

    // Traverse to the leftmost node, which will have the minimum value
    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    // Return the minimum value
    return temp->data;
}

// Find the maximum value in a binary search tree
int maxValBST(node *root)
{
    // Create a temporary node and initialize it with the root
    node *temp = root;

    // Traverse to the rightmost node, which will have the maximum value
    while (temp->right != NULL)
    {
        temp = temp->right;
    }

    // Return the maximum value
    return temp->data;
}

// Perform an inorder traversal of the binary tree
void inorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    // Recursively traverse the left subtree
    inorderTraversal(root->left);

    // Print the current node's data
    printf("%d ", root->data);

    // Recursively traverse the right subtree
    inorderTraversal(root->right);
}

// Perform an Preorder traversal of the binary tree
void preorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    // Print the current node's data
    printf("%d ", root->data);

    // Recursively traverse the left subtree
    preorderTraversal(root->left);

    // Recursively traverse the right subtree
    preorderTraversal(root->right);
}

// Perform an Postorder traversal of the binary tree
void postorderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    // Recursively traverse the left subtree
    postorderTraversal(root->left);

    // Recursively traverse the right subtree
    postorderTraversal(root->right);

    // Print the current node's data
    printf("%d ", root->data);
}

// Performing delete operation in Tree
node *deleteFromBST(node *root, int value)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data == value)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        // 1 child
         if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        //2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minValBST(root->right);
            root->data = mini;
            root->right = deleteFromBST(root->right, value);
            return root;
        }
    }
    else if (value > (root->data))
    {
        root->right = deleteFromBST(root->right, value);
        return root;
    }
    else
    {
        root->left = deleteFromBST(root->left, value);
        return root;
    }
}

int main()
{
    // Create the main root of the binary search tree
    node *root = NULL;

    // Take user input to build the binary search tree
    takeInput(&root);

    printf("Inorder Traversal\n");
    inorderTraversal(root);
    printf("\n");

    deleteFromBST(root, 10);
    deleteFromBST(root, 27);

    printf("Inorder Traversal\n");
    inorderTraversal(root);
    printf("\n");
    printf("Preorder Traversal\n");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal\n");
    postorderTraversal(root);
    printf("\n");

    // Find the minimum value in the binary search tree
    int minVal = minValBST(root);
    printf("Minimum Value in BST: %d\n", minVal);

    // Find the maximum value in the binary search tree
    int maxVal = maxValBST(root);
    printf("Maximum Value in BST: %d\n", maxVal);

    return 0;
}
