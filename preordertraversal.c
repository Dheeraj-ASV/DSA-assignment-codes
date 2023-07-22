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

struct TreeNode* constructTree()
{
   int data;
   printf("enter the data");
   scanf("%d",&data);
   if(data==-1)
    return NULL;
   struct TreeNode* newNode=createNode(data);
   printf("Enter the left child of %d:\n", data);
    newNode->left = constructTree();
    printf("Enter the right child of %d:\n", data);
    newNode->right= constructTree();

};

// Function to perform pre-order traversal of a binary tree
void preOrderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);      // Process the current node (root)
    preOrderTraversal(root->left);  // Traverse the left subtree
    preOrderTraversal(root->right); // Traverse the right subtree
}

// Function to free the memory allocated for the tree nodes
void freeTree(struct TreeNode* root) {
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    // Create a binary tree manually
    struct TreeNode* root = constructTree();


    // Perform pre-order traversal and print the nodes
    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    // Free the memory allocated for the tree nodes
    freeTree(root);

    return 0;
}
