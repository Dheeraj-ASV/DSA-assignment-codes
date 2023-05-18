// stacks basic operation using array

#include <stdio.h>
#include <stdlib.h>
#define max 100


typedef struct stack
{
    int arr[max];
    int top;
}stack;

int empty(stack s)
{
    if(s.top==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int full(stack s)
{
    if(s.top==max-1)
    {
        return 1;
    }
    else{return 0;}
}

void push(stack *s, int num)
{
    if(full(*s))
    {
        printf("stack is full\n");
        return;
    }
    s->top++;
    s->arr[s->top]=num;
}

void pop(stack *s)
{
    if(empty(*s))
    {
        printf("stack is empty\n");
        return;
    }
    s->top--;


}


int peak(stack *s)
{
    if(empty(*s))
    {
        printf("list is empty\n");
        return 0;
    }
    else
    {
        int temp_num;
        temp_num=s->arr[s->top];
        return temp_num;
    // printf("%d\n",s->arr[s->top]);
    }

}

void display(stack *s)
{
    if(empty(*s))
    {
        printf("list is empty\n");
        return;
    }
    int temp=0;
    while(temp<=s->top)
    {
        printf("%d\t",s->arr[temp]);
        temp++;
    }
    printf("\n");
    return ;
}

int main()
{
    stack s;
    s.top=-1;

    FILE *inputFile;
    if ((inputFile = fopen("inputFile.txt","w")) == NULL)
     {
       printf("Error! opening file");
       exit(1);
     }

    int lowerLimit,upperLimit,n;
    printf("Enter the lower limit of the number\n");
    scanf("%d",&lowerLimit);
    printf("\nEnter the upper limit of the number\n");
    scanf("%d",&upperLimit);
    printf("\nEnter the how many random-number has to be generated\n");
    scanf("%d",&n);

    upperLimit=upperLimit-lowerLimit;

    int i,rand_num;
    for(i=0;i<n;i++)
    {
        rand_num=(rand()%upperLimit);
        rand_num=rand_num+lowerLimit;
        fprintf(inputFile,"%d\n",rand_num);
    }
    fclose(inputFile);

    FILE *stackFile;
    int num;
    inputFile = fopen("inputFile.txt","r");
    stackFile = fopen("stackFile.txt","w");

        for
        (
            i=0;i<n;i++)
        {
            fscanf(inputFile,"%d",&num);
            push(&s,num);
            fprintf(stackFile,"%d\n",num);
        }
    fclose(stackFile);
    fclose(inputFile);
    //display(&s);
    printf("Random numbers are generated and pused into the stack\n");

    FILE *pushFile;
    FILE *popFile;
    FILE *logFile;

    //for inputs

    printf("1 push the number to stack file\n2.Push the data to pop file\n");
    int choice,pushCount=0,popCount=0;
    for(;;)
    {
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: //push to pushFile
                    num=peak(&s);
                    pushFile = fopen("pushFile.txt","a");
                    fprintf(pushFile,"%d\n",num);
                    fclose(pushFile);
                    pop(&s);
                    logFile = fopen("logFile.txt","a");
                    fprintf(logFile,"Push\n");
                    fclose(logFile);
                    break;

            case 2: //to put into popFile
                    num=peak(&s);
                    popFile = fopen("popFile.txt","a");
                    fprintf(popFile,"%d\n",num);
                    fclose(popFile);
                    pop(&s);
                    logFile = fopen("logFile.txt","a");
                    fprintf(logFile,"Pop\n");
                    fclose(logFile);
                    break;



            default : break;
        }
    }

    return 0;
}
