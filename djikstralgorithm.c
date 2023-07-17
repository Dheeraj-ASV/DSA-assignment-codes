#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000

struct node {
    int v;
    int weight;
    struct node* next;
};

void shortestPath(struct node* graph[], int start, int n);

struct node* createNode(int v, int weight) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->v = v;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct node* graph[], int src, int dest, int weight) {
    struct node* newNode = createNode(dest, weight);
    newNode->next = graph[src];
    graph[src] = newNode;
}

int main() {
    int i, j, m, n, v;
    printf("Enter the values of m and n: ");
    scanf("%d %d", &m, &n);

    int a[m][n];
    printf("Enter the values of the array:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the node v: ");
    scanf("%d", &v);

    // Create an array of linked lists to represent the graph
    struct node* graph[MAX];
    for (i = 0; i < MAX; i++)
        graph[i] = NULL;

    // Construct the graph from the given adjacency matrix
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] != 0) {
                addEdge(graph, i, j, a[i][j]);
            }
        }
    }

    shortestPath(graph, v, m);

    return 0;
}

void shortestPath(struct node* graph[], int start, int n) {
    int distance[MAX], visited[MAX], i, j;
    struct node* temp;
    for (i = 0; i < n; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }

    distance[start] = 0;

    for (i = 0; i < n - 1; i++) {
        int minDistance = INT_MAX;
        int minIndex = -1;

        // Find the vertex with the minimum distance
        for (j = 0; j < n; j++) {
            if (!visited[j] && distance[j] < minDistance) {
                minDistance = distance[j];
                minIndex = j;
            }
        }

        // Mark the selected vertex as visited
        visited[minIndex] = 1;

        // Update distances of the adjacent vertices of the selected vertex
        temp = graph[minIndex];
        while (temp != NULL) {
            if (!visited[temp->v] && distance[minIndex] != INT_MAX &&
                distance[minIndex] + temp->weight < distance[temp->v]) {
                distance[temp->v] = distance[minIndex] + temp->weight;
            }
            temp = temp->next;
        }
    }

    // Printing the shortest distances
    for (i = 0; i < n; i++) {
        if (distance[i] == INT_MAX) {
            printf("No path from %d to %d\n", start, i);
        } else {
            printf("Shortest distance from %d to %d: %d\n", start, i, distance[i]);
        }
    }
}



