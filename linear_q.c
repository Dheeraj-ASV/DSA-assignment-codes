#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the queue
typedef struct
{
    int data; // The data stored in the node
} Node;

// Structure to represent the queue
typedef struct
 {
    Node* queue; // Array to store the queue
    int front; // Index of the front element
    int rear; // Index of the rear element
    int size; // Current size of the queue
    int capacity; // Maximum capacity of the queue
} Queue;

// Function to initialize the queue
Queue* createQueue(int capacity)
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->queue = (Node*)malloc(capacity * sizeof(Node));
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = capacity;
    return q;
}

// Function to check if the queue is empty
int isEmpty(Queue* q)
{
    return q->size == 0;
}

// Function to check if the queue is full
int isFull(Queue* q)
{
    return q->size == q->capacity;
}

// Function to add an element to the rear of the queue
void enqueue(Queue* q, int data) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    q->rear++;
    q->queue[q->rear].data = data;
    q->size++;
}

// Function to remove an element from the front of the queue
int dequeue(Queue* q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int data = q->queue[q->front].data;
    q->front++;
    q->size--;
    return data;
}

// Function to get the front element of the queue without removing it
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot peek.\n");
        return -1;
    }
    return q->queue[q->front].data;
}

// Function to print the elements of the queue
void display(Queue* q)
{
   int i;
    if (isEmpty(q))
    {
        printf("Queue is empty. Nothing to display.\n");
        return;
    }
    printf("Queue: ");
    for (i = q->front; i <= q->rear; i++)
     {
        printf("%d ", q->queue[i].data);
    }
    printf("\n");
}

// Function to free the memory allocated to the queue
void destroyQueue(Queue* q)
{
    free(q->queue);
    free(q);
}
