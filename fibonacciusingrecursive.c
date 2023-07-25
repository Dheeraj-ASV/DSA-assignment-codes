//Code for example 1: Fibonacci using recursive algorithm
#include<stdio.h>
#include<stdlib.h>
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

int fibonacci(int n)
{
    stack s;
    s.top=-1;
    int result=0;
    push(&s,n);
    while(s.top!=-1)
    {
        int x=pop(&s);
        if(x<2)
        {
            result+=x;
        }
        else
        {
            push(&s,x-1);
            push(&s,x-2);
        }
    }
    return result;
}

int main()
{
    int n;
    printf("enter the number");
    scanf("%d",&n);
    printf("the gcd of two number %d is %d\n%d\n",n,fibonacci(n));
    return 0;
}
