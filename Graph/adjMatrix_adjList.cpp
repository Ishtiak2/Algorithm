#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V;  // Number of vertices
    vector<vector<int>> adjMatrix;  // Adjacency matrix
    vector<vector<int>> adjList;    // Adjacency list

public:
    Graph(int V) {
        this->V = V;
        adjMatrix.resize(V, vector<int>(V, 0));
        adjList.resize(V);
    }

    // Add an edge between u and v (undirected graph)
    void addEdge(int u, int v) {
        // For Adjacency Matrix
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;  // Undirected edge

        // For Adjacency List
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // Undirected edge
    }

    // Print the Adjacency Matrix
    void printAdjMatrix() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Print the Adjacency List
    void printAdjList() {
        cout << "Adjacency List:\n";
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            for (int j : adjList[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph g(5);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    // Print the adjacency matrix and list
    g.printAdjMatrix();
    g.printAdjList();

    return 0;
}
