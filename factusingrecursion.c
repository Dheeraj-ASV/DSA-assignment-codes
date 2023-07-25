#include<stdio.h>
#define size 100

typedef struct
{
int items[size];
int top;
}stack;

void push(stack *s,int value)
{
 if(s->top==size-1)
 {
     printf("stack overflow\n");
     return;
 }
 s->top++;
 s->items[s->top]=value;
}

int pop(stack *s)
{
    if(s->top==-1)
    {
        printf("stack underflow\n");
        return -1;
    }
    int value=s->items[s->top];
    (s->top)--;
    return value;
}

int factorial(int n)
{
    stack s;
    s.top=-1;
    int result=-1;
    push(&s,n);
    while(s.top!=-1)
    {
        int x=pop(&s);
        if(x>1)
       {
         push(&s,x-1);
         result =result*x;
       }
    }
    return result;
}

int main()
{
    int n;
    printf("enter the number");
    scanf("%d",&n);
    printf("the gcd of two number %d is %d\n%d\n",n,factorial(n));
    return 0;
}
