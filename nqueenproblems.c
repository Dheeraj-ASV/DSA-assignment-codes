#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int placement(int row,int col,int n)
int queen_function(int row,int n);
int display(int n);

int placement(int row,int col,int n)
{
    int count;
    for(count=1;count<=row-1;count++)
    if(board[col]==n)
    {
      return 0;
    }
    else
    {
        if((abs(board[count]-col))== (abs(count-row)))
           {
               return 0;
           }
        }
}


int queen_function(int row,int n)
{
    int col;
    for(col=1;col<=n;col++)
    {
        if(placement(row,col,n))
        {
            board[row]=col;
            if(row==n)
            {
                display(n);
            }
            else
            {
                queen_function(row+1,n);
            }
        }
}
}

int display(int n)
{
     int k,m;
     printf("solution %d\n",count++);
for(k=1;k<=n;k++)
{
    printf("%d",m);
}
for(k=1;k<=n;k++)
{
    printf("%d",m);
    for(m=1;m<=n;m++)
    {
        if(board[k]==m)
        {
            printf("\tQueen");
        }
        else
        {
             printf("\tx");
        }
    }
}
}

int main()
{
 int n;
printf("enter the number of queens");
scanf("%d",&n);
if(n<=3)
{
    printf("number should be greater than 3");
}
else
{
 queen_function(1,n);
}
printf("\n");
}



