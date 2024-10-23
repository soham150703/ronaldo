#include <stdio.h>
#include <limits.h>

#define MAX 10
#define INF 9999

int cost[MAX][MAX], n, goal[MAX], heuristic[MAX], solution[MAX], path[MAX], pathIndex = 0;

int minCost(int parent) {
    int min = INF;
    for (int i = 0; i < n; i++) {
        if (cost[parent][i] != INF && heuristic[i] < min) {
            min = heuristic[i];
        }
    }
    return min;
}

void AOStar(int node) {
    if (goal[node]) {
        solution[node] = 1;
        path[pathIndex++] = node;  // Add to path
        return;
    }

    int minSubCost = minCost(node);
    printf("Expanding node: %d with cost %d\n", node, minSubCost);
    path[pathIndex++] = node;  // Add to path

    for (int i = 0; i < n; i++) {
        if (cost[node][i] != INF && heuristic[i] == minSubCost) {
            AOStar(i);
            // Update heuristic of the node based on the sub-tree's solution
            heuristic[node] = minSubCost + cost[node][i];
            if (solution[i]) {
                solution[node] = 1;
                break;
            }
        }
    }
}

int main() {
    n = 5;  // Number of nodes
    
    // Hardcoded cost matrix
    int hardcoded_cost[5][5] = {
        {0, 3, INF, INF, INF},   // Costs from node 0
        {INF, 0, 2, 4, INF},     // Costs from node 1
        {INF, INF, 0, INF, 6},   // Costs from node 2
        {INF, INF, 1, 0, INF},   // Costs from node 3
        {INF, INF, INF, INF, 0}  // Costs from node 4 (goal)
    };

    // Copy the hardcoded cost matrix to the program's cost matrix
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cost[i][j] = hardcoded_cost[i][j];
        }
    }

    // Hardcoded heuristic values for each node
    int hardcoded_heuristic[5] = {3, 2, 1, 4, 0};
    
    // Copy hardcoded heuristic values
    for (int i = 0; i < 5; i++) {
        heuristic[i] = hardcoded_heuristic[i];
    }

    // Hardcoded goal nodes (0 = not goal, 1 = goal)
    int hardcoded_goal[5] = {0, 0, 0, 0, 1};  // Only node 4 is the goal
    
    // Copy hardcoded goal values
    for (int i = 0; i < 5; i++) {
        goal[i] = hardcoded_goal[i];
    }

    // Start node is hardcoded to node 0
    int start = 0;

    // Initialize the solution array to 0 (unsolved)
    for (int i = 0; i < n; i++) {
        solution[i] = 0;
    }

    // Call the AO* algorithm from the start node
    AOStar(start);

    // Output the solution path if a solution is found
    if (solution[start]) {
        printf("Solution found. Path: ");
        for (int i = 0; i < pathIndex; i++) {
            printf("%d ", path[i]);
        }
        printf("\n");
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
