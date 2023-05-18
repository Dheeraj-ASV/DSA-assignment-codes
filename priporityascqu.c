#include<stdio.h>
#include<stdlib.h>
#define SIZE 5 /* Size of Queue */
struct priorityq
{
 int items[SIZE],f,r;
};
typedef struct priorityq PQ;
int Qfull(PQ *pq1)
 { /* Function to Check Queue Full */
 if(pq1->r==SIZE-1)
 return 1;
 return 0;
 }
int Qempty(PQ *pq1)
 { /* Function to Check Queue Empty */
 if(pq1->f > pq1->r) return 1;
 return 0;
 }
void PQenqueue(PQ *pq1, int elem)
{
 int i; /* Function for Insert operation */
 if(Qfull(pq1))
 printf("Overflow!!!!\n");
 else
 {
 i=pq1->r;
 pq1->r++;
//if we change below condition to <= 0 function becomes descending priority queue.
 while(pq1->items[i] >= elem && i >= 0) /* Find location for new elem */
 {
 pq1->items[i+1]=pq1->items[i];
 i--;
 }
 pq1->items[i+1]=elem;
 }
}
int PQdequeue(PQ *pq1)
{ /* Function for Delete operation */
 int elem;
 if(Qempty(pq1))
 {
 printf("Underflow!!!!\n");
 return(-1);
 }
 else
 {
 elem=pq1->items[pq1->f];
 pq1->f=pq1->f+1;
 return(elem);
 }
}
void display(PQ *pq1)
{ /* Function to display status of Queue */
 int i;
 if(Qempty(pq1))
 printf("Empty Queue\n");
 else
 {
 for(i=pq1->f;i<=pq1->r;i++)
 printf("%d ",pq1->items[i]);
 }
}
int main()
{
 int opn,elem;
 PQ pq11, *pq1;
 pq1=&pq11;
 pq1->f = 0;
 pq1->r=-1;
 while(1)
 {
 printf("\nPriority Queue Operations(ASC order)\n");
 printf("1.Enqueue. 2.Dequeue. 3.Display. 4. Exit\n");
 printf("Enter choice\n");
 scanf("%d",&opn);
 switch(opn)
 {
 case 1: printf("Enter element\n");
 scanf("%d",&elem);
 PQenqueue(pq1, elem);
 break;
 case 2: elem=PQdequeue(pq1);
 if( elem != -1)
 printf("Dequeued Element is %d \n",elem);
 break;
 case 3: printf("Status of Queue\n");
 display(pq1);
 break;
 case 4: exit(0);
 break;
 default: printf("Invalid Option\n");
 }

}
 return 0;
 }
