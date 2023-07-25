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

int gcd(int a,int b)
{
    stack s;
    s.top=-1;
    push(&s,a);
    push(&s,b);
    int x,y;
    while(s.top>=1)
    {
      y=pop(&s);
      x=pop(&s);
      push(&s,y%x);
      push(&s,x);
    }
 return pop(&s);
}

int main()
{
    int a,b;
    printf("enter the number");
    scanf("%d%d",&a,&b);
    printf("the gcd of two number %d is %d\n%d\n",a,b,gcd(a,b));
    return 0;
}
