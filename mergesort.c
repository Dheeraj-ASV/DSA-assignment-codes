#include<stdio.h>
#include<stdlib.h>


void merge(int a[],int l,int m,int r)
{
    int i,j,k;
    int n1=m-1+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
    {
       L[i]=a[l+i];
        for(j=0;j<n2;j++)
        {
            R[j]=a[m+1+j];
        }
    }

        i=0;
        j=0;
        k=l;
        while(i<n1&&j<n2)
        {
            if(L[i]<=R[j])
            {
                a[k]=L[i];
                i++;
            }
            k++;
        }
        while(i<n1)
        {
            a[k]=R[j];
            j++;
            k++;
        }
}

void mergesort(int a[],int l,int r)
{
    if(l < r)
    {
        int m;
        m=l+(r-1)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a, l, m, r);
    }
}

void printarray(int arr[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}

int main()
{
    int a[]={12,11,13,5,6,7};
    int a_size=sizeof(a)/sizeof(a[0]);
    printf("given array is \n");
    printarray(a,a_size);
    mergesort(a,0,a_size-1);
    printf("\nsorted array is \n");
    printarray(a,a_size);
    return 0;
}

