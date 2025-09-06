#include <bits/stdc++.h>
using namespace std;

class Solution {
    // DFS to fill stack according to finishing time
    void dfs1(int node, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &st) {
        vis[node] = true;
        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfs1(neighbor, adj, vis, st);
            }
        }
        st.push(node); // all descendants processed, push to stack
    }

    // DFS on the transposed graph
    void dfs2(int node, vector<vector<int>> &adjT, vector<bool> &vis) {
        vis[node] = true;
        for (int neighbor : adjT[node]) {
            if (!vis[neighbor]) {
                dfs2(neighbor, adjT, vis);
            }
        }
    }

public:
    // Returns the number of strongly connected components
    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size();

        // Step 1: DFS to get finishing times
        vector<bool> vis(V, false);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs1(i, adj, vis, st);
            }
        }

        // Step 2: Transpose the graph
        vector<vector<int>> adjT(V);
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                adjT[v].push_back(u); // reverse edge
            }
        }

        // Step 3: DFS in the order of the stack on the transposed graph
        fill(vis.begin(), vis.end(), false);
        int sccCount = 0;

        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (!vis[node]) {
                sccCount++;
                dfs2(node, adjT, vis);
            }
        }

        return sccCount;
    }
};

int main() {
    // Example: Graph with 5 nodes
    vector<vector<int>> adj = {
        {2, 3}, // 0
        {0},    // 1
        {1},    // 2
        {4},    // 3
        {}      // 4
    };

    Solution sol;
    int result = sol.kosaraju(adj);

    cout << "Number of Strongly Connected Components: " << result << endl;
    return 0;
}
