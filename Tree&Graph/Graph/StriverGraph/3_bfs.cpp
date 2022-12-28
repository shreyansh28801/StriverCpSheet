#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], vector<bool> &visited, int node)
{

    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while (!q.empty())
    {
        int d = q.front();
        cout << d << "  ";
        q.pop();
        for (int j : adj[d])
        {
            if (!visited[j])
            {
                q.push(j);
                visited[j] = 1;
            }
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
            bfs(adj, vis, i);
        }
    }

    //T . C.  =>   O(n){component loop} + O(n + e) {traversing adjacency list of  n nodes}  =>   O(2n +e )
    //S . C.  =>    O(n+e){for storing adjacency list} + O(n){visited array } + O(n) {queue d.s.}  =>   O(3n+e)

    return 0;
}