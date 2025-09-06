#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int v, vector<vector<pair<int,int>>> & adj, int source){
    vector<int> dist(v+1,INT_MAX);
    dist[source] = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    pq.push({0,source});

    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        for(auto it: adj[node]){
            int wt = it.second;
            int adjNode = it.first;

            if(d + wt < dist[adjNode]){
                dist[adjNode] = d + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;

}

int main()
{
    int v = 6;
    int e = 8;
    vector<vector<pair<int,int>>> adj(v+1);
    for(int i = 0; i < e; i++){
        int u,v,wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    
    vector<int> dist = dijkstra(v,adj,0);

    for(int i = 0; i < v; i++) cout<<dist[i]<<" ";

    return 0;
}
/*
input:

0 1 4
0 2 4
1 2 2
2 3 3
2 5 6
2 4 1
3 5 2
4 5 3
*/