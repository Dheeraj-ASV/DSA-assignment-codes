#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insert(struct TreeNode* root,int data)
{
 if(root==NULL)
    return createNode(data);
if(data<root->data)
{
    root->left=insert(root->left,data);
}
else if(data > root->data)
{
    root->right=insert(root->right,data);
}
}

void inOrderTraversal(struct TreeNode* root,int *prev,int* duplicates)
{
    if(root==NULL)
        return;
        inOrderTraversal(root->left,prev,duplicates);

        if(*prev==root->data)
        {
            (*duplicates)++;
            printf("duplicate ele %d",root->data);

        }

        *prev=root->data;
        inOrderTraversal(root->right,prev,duplicates);
}

void freeTree(struct TreeNode* root)
{
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main()
{
struct TreeNode* root = NULL;
    int data;

    // Take input from the user to construct the Binary Search Tree
    printf("Enter elements (-1 to stop):\n");
    while (1)
    {
        scanf("%d", &data);
        if (data == -1)
            break;
        root=insert(root,data);
    }

    int prev = -1;
    int duplicates = 0;

    // Perform in-order traversal to find and print duplicate elements
    printf("Duplicate elements in the tree:\n");
    inOrderTraversal(root, &prev, &duplicates);

    if (duplicates == 0)
    {
        printf("No duplicates found.\n");
    }

    // Free the memory allocated for the tree nodes
    freeTree(root);

    return 0;
}
