#include <stdio.h>
#include <stdlib.h>
typedef int bool;

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

int findShortestPath(struct TreeNode* root, int src, int dest) {
    if (root == NULL) {
        return -1; // Tree is empty
    }

    // Create a queue for BFS
    struct TreeNode* queue[100];
    int front = -1, rear = -1;

    // Enqueue the root node
    queue[++rear] = root;

    while (front != rear) {
        struct TreeNode* currentNode = queue[++front];

        if (currentNode->data == dest) {
            return front; // Shortest path length is equal to front (level in BFS)
        }

        if (currentNode->left != NULL) {
            queue[++rear] = currentNode->left;
        }
     if (currentNode->right != NULL) {
            queue[++rear] = currentNode->right;
        }
    }

    return -1; // The destination node is not reachable from the source node
}

int main()
{
    struct TreeNode* root=NULL;
    int n,data,src,dest,i;
    printf("enter the number of nodes in the binary tree:");
    scanf("%d",&n);

     printf("enter the number of elements in the binary tree:");
    for(i=0;i<n;i++)
    {
    scanf("%d",&data);
    root=createNode(data);
    }

    printf("enter the source node:");
    scanf("%d",&src);
      printf("enter the destination node:");
    scanf("%d",&dest);
    int shortestPath = findShortestPath(root, src, dest);
    if (shortestPath != -1) {
        printf("The shortest path from node %d to node %d is: %d\n", src, dest, shortestPath);
    } else {
        printf("The destination node is not reachable from the source node.\n");
    }

    // Free allocated memory (Note: This is a simple example; proper memory deallocation is essential in real applications)
    return 0;
}

