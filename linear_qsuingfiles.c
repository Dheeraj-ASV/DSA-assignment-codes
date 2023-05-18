#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct QueueRecord {
    int front;
    int rear;
    int array[SIZE];
};

typedef struct QueueRecord Queue;

int IsFULL(Queue);
int IsEmpty(Queue);
void Enqueue(Queue *, int);
int Dequeue(Queue *);
void display(Queue);
Queue CreateQueue();

Queue CreateQueue() {
    Queue Q;
    Q.rear = -1;
    Q.front = -1;
    return Q;
}

int IsFULL(Queue Q) {
    if (Q.rear == SIZE - 1)
        return 1;
    else
        return 0;
}

int IsEmpty(Queue Q) {
    if (Q.rear == -1 || Q.front >= Q.rear)
        return 1;
    else
        return 0;
}

void Enqueue(Queue *Q, int element) {
    if (IsFULL(*Q)) {
        printf("Queue is full\n");
    } else {
        Q->rear = Q->rear + 1;
        Q->array[Q->rear] = element;
    }
}

int Dequeue(Queue *Q) {
    if (IsEmpty(*Q)) {
        printf("Queue is Empty\n");
        return -1;
    } else {
        Q->front++;
        return Q->array[Q->front];
    }
}

void display(Queue Q) {
    int i;
    if (IsEmpty(Q))
        printf("Queue is empty\n");
    else {
        printf("Queue is:\n");
        for (i = Q.front + 1; i <= Q.rear; i++)
            printf("%d ", Q.array[i]);
        printf("\n");
    }
}

int main() {
    int i, ch, n, item, x;
    Queue Q;

    Q = CreateQueue();
    FILE *fp;
    fp = fopen("output.txt", "w");

    while (1) {
        printf("1-Insert\n2-Remove Element\n3-Display\n4-Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                Enqueue(&Q, item);
                break;

            case 2:
                x = Dequeue(&Q);
                if (x != -1) {
                    printf("Removed Element is = %d\n", x);
                    fprintf(fp, "Removed Element is = %d\n", x);
                }
                break;

            case 3:
                display(Q);
                fprintf(fp, "Displaying the queue\n");
                break;

            case 4:
                fclose(fp);
                exit(0);
                break;
        }
    }

    return 0;
}

