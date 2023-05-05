#include<stdio.h>
#include<string.h>
#include<time.h>
#define size 10000

void print_array(int a[size],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
void bubblesort(int a[size],int n)
{
  int i,j,temp;
  for(i=0;i<n-1;i++)
  {
  for(j=0;j<n-i-1;j++)
  {
   if(a[j]>a[j+1])
   {
     temp=a[j];
     a[j]=a[j+1];
     a[j+1]=temp;
   }
  }
  }
  printf("After sorting...\n");
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
}
void selectionsort(int a[size],int n)
{
   int i,indexofmin,temp,j;
   for(i=0;i<n;i++)
   {
       indexofmin=i;

       {
           if(a[j]<a[indexofmin])
           {
               indexofmin=j;
           }
       }
       temp=a[i];
       a[i]=a[indexofmin];
       a[indexofmin]=temp;
   }
    printf("After selectionsorting...\n");
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
}
void insertionsort(int a[size],int n)
{
    int key,i,j;
    for(i=1;i<n;i++)
    {
       j=i-1;
       key=a[i];
       while(j>=0 && a[j]<key )
       {
           a[j+1]=a[j];
           j--;
       }
       a[j+1]=key;
    }
}
int main()
{
    int a[size],n,rnum,i;
    float duration;
    clock_t start,end;
    int first,last;
    printf("Enter the interval\n");
    scanf("%d%d",&first,&last);
    printf("Enter number of random numbers to be generated\n ");
    scanf("%d",&n);
    //read_array(a,n);
    for(i=0;i<n;i++)
    {
        a[i]=rand()%(last+1-first)+first;

    }
    start=clock();
    bubblesort(a,n);
    end=clock();
    duration=(float)(end-start);//(CLOCKS_PER_SEC);
    printf("\nduration is for bubble sort %f\n",duration);
    start=clock();
    selectionsort(a,n);
     end=clock();
     duration=(float)(end-start);//(CLOCKS_PER_SEC);
     printf("\nduration is for selection sort %f\n",duration);
     start=clock();
     insertionsort(a,n);
     end=clock();
     duration=(float)(end-start);//(CLOCKS_PER_SEC);
     printf("\nduration is for insertion sort %f\n",duration);
    print_array(a,n);
    return 0;
}
