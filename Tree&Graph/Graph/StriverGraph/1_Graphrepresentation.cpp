#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /********
     * 
     * 
     * 
    //Matrix Representation of Graph
    int n,e;//n,e denotes no. of nodes and edeges respectively
    cin>>n>>e;
    int graph[n+1][n+1];
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            graph[i][j]=0;
        }
    }
    //next e lines has edeges details;
    for (int i = 0; i < e; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }

    ******/

    int n, e; //n,e denotes no. of nodes and edeges respectively
    cin >> n >> e;
    vector<int> adj[n + 1]; //assuming 1 base indexing of nodes

    //next e lines has edeges details;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << i << " ----->  ";
        for (int v : adj[i])
        {
            cout << "   " << v;
        }
        cout << "\n";
    }

    /********
     * 
     * 
     * 
    //Adjacency list Representation Of graph with weight assign to every edeges
    int n,e;//n,e denotes no. of nodes and edeges respectively
    cin>>n>>e;
    vector<pair<int,int>> adj[n+1];//assuming 1 base indexing of nodes
  
    //next e lines has edeges details;
    for (int i = 0; i < e; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    ******/

    return 0;
}