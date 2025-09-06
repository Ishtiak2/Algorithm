#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define optimize() ios_base:: sync_with_stdio (0) ; cin.tie (0) ; cout.tie (0) ;

vector<int> bellmanFord(int n, vector<vector<int>> &edges, int source){
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    for(int i = 1; i <= n; i++){
        for(vector<int> it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                if(i == n) return {-1};
                dist[v] = dist[u] + wt;
            }
        }
    }

    return dist;

}

int main()
{
    optimize();
    int V = 5;
	vector<vector<int>> edges = {{1, 3, 2}, {4, 3, -1}, {2, 4, 1}, 
                                 {1, 2, 1}, {0, 1, 5}};

	int src = 0;
	vector<int> ans = bellmanFord(V, edges, src);
	for (int dist : ans) 
		cout << dist << " ";

    return 0;
}