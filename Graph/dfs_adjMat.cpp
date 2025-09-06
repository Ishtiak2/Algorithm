#include <bits/stdc++.h>
using namespace std;

class Graph {
    int v;
    vector<vector<int>> adjMatrix;

public:
    Graph(int v) {
        this->v = v;
        adjMatrix.resize(v, vector<int>(v, 0)); // Initialize VxV matrix with 0s
    }

    void addEdge(int x, int y) {
        adjMatrix[x][y] = 1;
        adjMatrix[y][x] = 1; // Undirected graph
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

            for (int i = 0; i < v; i++) {
                if (adjMatrix[node][i] == 1 && !visited[i]) {
                    qu.push(i);
                    visited[i] = true;
                }
            }
        }

        cout << endl;
    }

    void DFS(int start) {
        vector<bool> visited(v, false);
        stack<int> st;

        st.push(start);
        visited[start] = true;

        while (!st.empty()) {
            int node = st.top();
            st.pop();
            cout << node << " ";

            for (int i = v - 1; i >= 0; i--) { // Reverse order for correct DFS traversal
                if (adjMatrix[node][i] == 1 && !visited[i]) {
                    st.push(i);
                    visited[i] = true;
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

    cout << "BFS Traversal: ";
    g.BFS(0);

    cout << "DFS Traversal: ";
    g.DFS(0);

    return 0;
}
