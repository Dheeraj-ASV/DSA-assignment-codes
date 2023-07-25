//Fibonacci series
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
    push(&s,n);
    int fib[n+2],i;
    fib[0]=0;
    fib[1]=1;
    for(i=2;i<=n;i++)
    {
        int a = pop(&s);
        push(&s,a-1);
        push(&s,a-2);
        fib[i]=fib[i-1]+fib[i-2];

    }
    return fib[n];
}

int main()
{
    int n;
    printf("enter the number");
    scanf("%d",&n);
    printf("the fibonacci number %d is %d\n",n,fibonacci(n));
    return 0;
}
