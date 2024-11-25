#include <stdio.h>
#include <limits.h>
#define MAX 10

int graph[MAX][MAX];         // Adjacency matrix to represent the graph
int heuristic[MAX];          // Heuristic values for each node
int visited[MAX];            // Array to track visited nodes
int cost[MAX];               // Cost array to track g(n) values
int priorityQueue[MAX];      // Priority queue to hold nodes
int priority[MAX];           // Priority values corresponding to nodes in the queue
int front = -1, rear = -1;   // Queue pointers

// Enqueue operation for the priority queue
void enqueue(int node, int fValue) {
    if (rear == MAX - 1) {
        printf("Priority Queue is full!\n");
        return;
    }
    if (front == -1) front = 0;
    rear++;

    priorityQueue[rear] = node;
    priority[rear] = fValue;

    // Sort the queue based on f(n) values (ascending order)
    for (int i = rear; i > front; i--) {
        if (priority[i] < priority[i - 1]) {
            // Swap elements in priorityQueue
            int tempNode = priorityQueue[i];
            priorityQueue[i] = priorityQueue[i - 1];
            priorityQueue[i - 1] = tempNode;

            // Swap corresponding f(n) values
            int tempPriority = priority[i];
            priority[i] = priority[i - 1];
            priority[i - 1] = tempPriority;
        }
    }
}

// Dequeue operation for the priority queue
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Priority Queue is empty!\n");
        return -1;
    }
    int node = priorityQueue[front];
    front++;
    return node;
}

// Check if the priority queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// A* Algorithm
void aStar(int start, int goal, int numVertices) {
    // Initialize costs
    for (int i = 0; i < numVertices; i++) {
        cost[i] = INT_MAX;
    }
    cost[start] = 0;

    enqueue(start, heuristic[start]); // f(n) = g(n) + h(n)
    visited[start] = 1;

    printf("Path: ");
    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        if (current == goal) {
            printf("\nGoal %d reached!\n", goal);
            return;
        }

        for (int i = 0; i < numVertices; i++) {
            if (graph[current][i] > 0 && !visited[i]) { // Adjacent and unvisited
                int newCost = cost[current] + graph[current][i]; // g(n)
                if (newCost < cost[i]) {
                    cost[i] = newCost;
                    int fValue = newCost + heuristic[i]; // f(n) = g(n) + h(n)
                    enqueue(i, fValue);
                }
                visited[i] = 1;
            }
        }
    }
    printf("\nGoal not reachable!\n");
}

// Main function
int main() {
    int numVertices, start, goal;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    // Input adjacency matrix
    printf("Enter the adjacency matrix (use weight values for edges, 0 for no edge):\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Input heuristic values
    printf("Enter the heuristic values for each vertex:\n");
    for (int i = 0; i < numVertices; i++) {
        scanf("%d", &heuristic[i]);
        visited[i] = 0; // Initialize visited array
    }

    // Input start and goal nodes
    printf("Enter the start vertex: ");
    scanf("%d", &start);
    printf("Enter the goal vertex: ");
    scanf("%d", &goal);

    // Perform A* Algorithm
    aStar(start, goal, numVertices);

    return 0;
}
