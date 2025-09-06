#include <bits/stdc++.h>
using namespace std;

class Graph {
    int v;
    vector<vector<int>> adjList;

public:
    Graph(int v) {
        this->v = v;
        adjList.resize(v);
    }

    void addEdge(int x, int y) {
        adjList[x].push_back(y);
        adjList[y].push_back(x); // Undirected graph
    }

    void BFS(int start) {
        vector<bool> visited(v, false);
        queue<int> qu;

        qu.push(start);
        visited[start] = true;

        while (!qu.empty()) {
            int node = qu.front();
            qu.pop();
            cout << node << " ";

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    qu.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        cout << endl;
    }
};

int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    g.BFS(0);

    return 0;
}
