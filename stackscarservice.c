#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct stack
{
    int top;
    int items[MAX];
} STACK;

int isFull(STACK *s);
void initstack(STACK *s);
void push(STACK *s,int e);
void pop(STACK *s);
int isEmpty(STACK *s);
void peek(STACK *s);
void display(STACK *s);

int main()  // Corrected the declaration of main
{
    int ch, carNumber;
    STACK s;
    initstack(&s);
    while(1)
    {
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.PEEK\n");
        printf("4.display\n");
        printf("5.EXIT\n");
        printf("ENTER YOUR CHOICE\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("ENTER THE NUMBER OF THE CAR\n");
                   scanf("%d",&carNumber);  // Corrected the input type
                   push(&s,carNumber);
                   break;
            case 2:pop(&s);
                   break;
            case 3:peek(&s);
                   break;
            case 4:display(&s);
                   break;  // Added a break statement
            case 5:exit(0);
        }
    }
    return 0;
}

int isFull(STACK *s)
{
    return s->top==MAX-1;
}

void initstack(STACK *s)
{
    s->top=-1;
}

int isEmpty(STACK *s)
{
    return s->top==-1;
}

void push(STACK *s,int e)
{
    if(isFull(s))
    {
        printf("STACK IS FULL\n");
        return;
    }
    s->items[++s->top]=e;
}

void pop(STACK *s)
{
    if(isEmpty(s))
    {
        printf("STACK EMPTY\n");
        return;
    }
    int carNumber;
    carNumber=s->items[s->top--];
    printf("\n%d\n",carNumber);
}

void peek(STACK *s)
{
    if(isEmpty(s))
    {
        printf("EMPTY STACK\n");
    }
    else
    {
        printf("Top of the stack: %d\n", s->items[s->top]);
    }
}

void display(STACK *s)
{
    int i;
    if(isEmpty(s))
    {
        printf("STACK EMPTY\n");
    }
    else
    {
        printf("Stack: ");
        for(i=0; i<=s->top; i++)
        {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}







