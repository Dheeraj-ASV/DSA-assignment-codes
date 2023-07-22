#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data)
{
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void postOrderTraversal(struct TreeNode* root)
{
    if (root == NULL)
        return;

    postOrderTraversal(root->left);  // Traverse the left subtree
    postOrderTraversal(root->right);// Traverse the right subtree
    printf("%d ", root->data);
}

struct TreeNode* buildTreeFromUserInput() {
    char data;
    printf("Enter data (or 'x' to stop): ");
    scanf(" %c", &data);

    if (data == 'x') {
        return NULL;
    }

    struct TreeNode* newNode = createNode(data);

    printf("Enter the left child of %c:\n", data);
    newNode->left = buildTreeFromUserInput();

    printf("Enter the right child of %c:\n", data);
    newNode->right = buildTreeFromUserInput();

    return newNode;
}

int main()
{
    printf("enter the elements of the binary tree(enter x for no child):");
    struct TreeNode* root=buildTreeFromUserInput();
    printf("post order traversal:");
    printf("\n");
    return 0;
}

