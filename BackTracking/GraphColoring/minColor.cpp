#include <bits/stdc++.h>
using namespace std;

const int V = 4;
int colors[V];
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

bool graphColoring(int vertex, int m) {
    if (vertex == V) return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(vertex, c)) {
            colors[vertex] = c;
            if (graphColoring(vertex + 1, m)) return true;
            colors[vertex] = 0; // backtrack
        }
    }
    return false;
}

int findChromaticNumber() {
    for (int m = 1; m <= V; m++) {
        
        for(int i = 0; i < V; i++) colors[i] = 0;

        if (graphColoring(0, m)) {
            return m; // minimum colors needed
        }
    }
    return V; // worst case: each vertex has its own color
}

int main() {
    int chromatic = findChromaticNumber();
    cout << "Minimum number of colors needed (Chromatic Number): " << chromatic << endl;
    return 0;
}
