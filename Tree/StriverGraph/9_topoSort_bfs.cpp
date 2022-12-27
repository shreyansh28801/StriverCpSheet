#include <bits/stdc++.h>
using namespace std;

//Topo Sort is defined for DAG(Directed Acyclic Graph)

void topoSort(vector<bool> &inDeg, vector<int> adj[], queue<int> &q)
{
    while (q.size() > 0)
    {
        int node = q.front();
        cout << node << "   ";
        q.pop();
        for (int it : adj[node])
        {
            inDeg[it] = inDeg[it] - 1;
            if (inDeg[it] == 0)
                q.push(it);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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

    vector<bool> inDeg(n + 1, 0);
    //storing in degree of each node
    for (int i = 1; i < n + 1; i++)
    {
        for (int it : adj[i])
        {
            inDeg[it] = inDeg[it] + 1;
        }
    }
    queue<int> q;
    for (int i = 1; i < n + 1; i++)
    {
        if (inDeg[i] == 0)
        {
            q.push(i);
        }
    }

    topoSort(inDeg, adj, q);

    return 0;
}