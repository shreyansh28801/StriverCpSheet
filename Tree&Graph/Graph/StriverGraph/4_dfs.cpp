#include <bits/stdc++.h>

using namespace std;

void dfs(vector<bool> &vis, vector<int> adj[], int node)
{
    cout << node << "     ";
    vis[node] = 1;
    for (int it : adj[node])
    {
        if (!vis[it])
        {
            dfs(vis, adj, it);
        }
    }
    return;
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
    vector<bool> vis(n + 1, 0);
    for (int i = 1; i < n + 1; i++)
    {
        if (!vis[i])
        {
            dfs(vis, adj, i);
        }
    }

    //T . C.  =>   O(n){component loop} + O(n + e) {traversing adjacency list of  n nodes}  =>   O(2n +e )
    //S . C.  =>    O(n+e){for storing adjacency list} + O(n){visited array } + O(n) {queue d.s.}  =>   O(3n+e)

    return 0;
}