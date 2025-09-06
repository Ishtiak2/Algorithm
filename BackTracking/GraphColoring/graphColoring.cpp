#include <iostream>
using namespace std;

const int V = 4; // Number of vertices

// Function to check if the current color assignment is safe for vertex
bool isSafe(int vertex, int graph[V][V], int colors[V], int color) {
    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] && colors[i] == color) {
            return false; // Adjacent vertex has the same color
        }
    }
    return true;
}

// Backtracking function to solve the graph coloring problem
bool graphColoring(int graph[V][V], int m, int colors[V], int vertex) {
    if (vertex == V) { // All vertices are assigned a color
        // Print the solution
        cout << "Solution: ";
        for (int i = 0; i < V; i++)
            cout << colors[i] << " ";
        cout << endl;
        return true; // Return true to find **one solution**
    }

    // Try all colors for the current vertex
    for (int c = 1; c <= m; c++) {
        if (isSafe(vertex, graph, colors, c)) {
            colors[vertex] = c; // Assign color

            if (graphColoring(graph, m, colors, vertex + 1))
                return true; // If solution found, return

            colors[vertex] = 0; // Backtrack
        }
    }

    return false; // No color can be assigned
}

int main() {
    // Example graph represented as adjacency matrix
    int graph[V][V] = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 0},
        {0, 1, 0, 0}
    };

    int m = 3; // Number of colors
    int colors[V] = {0}; // Store colors assigned to vertices

    if (!graphColoring(graph, m, colors, 0))
        cout << "No solution exists with " << m << " colors." << endl;

    return 0;
}
