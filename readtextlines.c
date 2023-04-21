#include <stdio.h>
void read(char str[10][100]);
int checklength(char str[10][100]);


int main()
{
    char str[10][100];
    read(str);
    int maxlenght;
    maxlenght=checklength(str);
    return 0;
}

void read(char str[10][100])
{
    int i;
    for(i=0;i<3;i++)
    {
        gets(str[i]);
    }
}


int checklength(char str[10][100])
{
    int maxlenght;
    int i,j,count=0;
   for(i=0;i<3;i++)
    {
        for(j=0;str[i][j]!='\0';j++)
        {
            count++;
        }
        if(count>maxlenght)
        {
            maxlenght=count;
        }
        count=0;
    }
    printf("%d",maxlenght);
    return maxlenght;
}

