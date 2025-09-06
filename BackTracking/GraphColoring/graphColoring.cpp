#include <bits/stdc++.h>
using namespace std;

const int V = 4;
int colors[V];
int m = 3;

int graph[V][V] = {
    {0, 1, 1, 0},
    {1, 0, 1, 1},
    {1, 1, 0, 0},
    {0, 1, 0, 0}
};

bool isSafe(int vertex, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[vertex][i] && colors[i] == c)
            return false;
    }
    return true;
}

void printSolution() {
    cout << "Coloring: ";
    for (int i = 0; i < V; i++) {
        cout << colors[i] << " ";
    }
    cout << endl;
}

bool graphColoring(int vertex) {
    if (vertex == V) {
        printSolution();
        return true;
    }

    bool found = false;
    for (int c = 1; c <= m; c++) {
        if (isSafe(vertex, c)) {
            colors[vertex] = c;
            found = graphColoring(vertex + 1) || found;
            colors[vertex] = 0; // backtrack
        }
    }
    return found;
}

int main() {
    if (!graphColoring(0)) {
        cout << "Not possible!" << endl;
    }
    return 0;
}
