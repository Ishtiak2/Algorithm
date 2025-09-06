#include<bits/stdc++.h>
using namespace std;

class Graph{
    int v;
    vector< vector<int> > adjMatrix;

    public:

    Graph(int v)
    {
        this -> v= v;
        adjMatrix.resize(v,vector<int>(v,0)); //Initialize as a VxV matrix with 0s
    }

    void addEdge(int x, int y) {
        adjMatrix[x][y] = 1;
        adjMatrix[y][x] = 1;
    }

    void BFS(int start) {
        
        vector<bool> visited(v,false);
        queue<int> qu;

        qu.push(start);
        visited[start] = true;

        while(!qu.empty()) {
            
            int node = qu.front();
            qu.pop();

            cout << node <<" ";
            for(int i = 0; i < v; i++)
            {
                if(adjMatrix[node][i] == 1 && visited[i] == false) {
                    
                    qu.push(i);
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

    g.BFS(0);

    return 0;
}