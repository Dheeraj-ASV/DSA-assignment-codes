#include<stdio.h>
void readarr(int a[],int n);
void printarr(int a[],int n);
void binarysearch(int a[],int n,int ele);

int main()
{
   int a[10],n,ans,ele;
    printf("Enter the value for n\n");
    scanf("%d",&n);
    readarr(a,n);
    printarr(a,n);
    printf("\nEnter the element to search\n");
    scanf("%d",&ele);
    binarysearch(a,n,ele);
}

void readarr(int a[],int n)
{
   printf("enter the values for the arrays\n");
   int i;
    for(i=0;i<n;i++)
     {
         scanf("%d\t",a[i]);
        }
}

void printarr(int a[],int n)
  {
    printf("enter the values for the arrays\n");
     int i;
       for(i=0;i<n;i++)
        {
           printf("%d\t",a[i]);
         }
}

void  binarysearch(int a[],int n,int ele)
{
  int first=0;
  int last;
  last=n-1;
        int middle;
         middle=(first+last)/2;
         while (first<=last)
        {
              if (a[middle] < ele)
       {
                first = middle + 1;
            }
            else if (a[middle] == ele)
            {
                printf("%d found at index %d\n", ele, middle);
                break;
            }
            else
            {
                last = middle - 1;
            }

            middle = (first + last)/2;
        }
    if (first > last)
      printf("Not found\n", ele);
}
