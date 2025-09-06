#include <bits/stdc++.h>
using namespace std;

void dfsUtil(vector<bool> &vis, vector<vector<int>> &adj,int s,vector<int> &vertex){
    vis[s] = true;
    vertex.push_back(s);

    for(auto it: adj[s]){
        if(vis[it] != true){
            dfsUtil(vis,adj,it,vertex);
        }
    }

}
vector<int> dfs(int v, vector<vector<int>> & adj,int start){
    vector<bool> vis(v,false);
    vector<int> vertex;
    dfsUtil(vis,adj,start,vertex);
    return vertex;
}

int main() {
    int v = 5;
    vector<vector<int>> adj(v);

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);
    adj[1].push_back(0);
    adj[2].push_back(0);
    adj[2].push_back(4);

    vector<int> vertex = dfs(v,adj,0);
    cout << "DFS Traversal: ";
    for(auto it: vertex){
        cout<<it<<" ";
    }

    return 0;
}
