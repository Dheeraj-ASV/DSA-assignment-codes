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


bool findPath(struct TreeNode* root, int target,int path[],int level)
{

if(root==NULL)
{
  return 0;
}

path[level]=root->data;
level++;
int i;

if(root->data==target)
{
 printf("path found:");
 for(i=0;i<level;i++)
 {
   printf("%d",path[i]);
 }
 printf("\n");
 return 1;

}
 if (findPath(root->left, target, path, level) || findPath(root->right, target, path, level)) {
        return 1;
    }

    return 0;
}



int main()
{
    struct TreeNode* root=NULL;
    int n,data,target,i;
    printf("enter the number of nodes in the binary tree:");
    scanf("%d",&n);

    printf("enter the number of elements to be created",n);
    for(i=0;i,n;i++)
    {
        scanf("%d",&data);
        root=insert(root,data);
    }
printf("enter the target node to find the path to:");
scanf("%d",&target);

int path[100];
if(!findPath(root,target,path,0))
{
    printf("path not found for target %d",target);
}
}
