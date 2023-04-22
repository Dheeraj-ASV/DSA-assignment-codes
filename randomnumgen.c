#include<stdio.h>
int main()
{
int p,q,i,temp,n;
printf("enter the values for p,q and n");
scanf("%d%d%d",&p,&q,&n);
q=q-p;
int arr[n];
FILE *fptr;
fptr=fopen("randnumgen.txt","w");
if(fptr==NULL)
{
    printf("Error");
    exit(1);
}
for(i=0;i<n;i++)
{
temp=(rand()%q);
temp=temp+p;
printf("%d\n",temp);
fprintf(fptr,"%d\n",temp);
}
}
