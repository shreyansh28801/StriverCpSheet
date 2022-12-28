#include <bits/stdc++.h>
using namespace std;

void topoSort(vector<bool> &vis, vector<int> adj[], int node, stack<int> &st)
{
    vis[node] = 1;
    for (int it : adj[node])
    {
        if (!vis[it])
            topoSort(vis, adj, it, st);
    }
    st.push(node);
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
    stack<int> stk;
    vector<bool> vis(n + 1, 0);
    for (int i = 1; i < n + 1; i++)
    {
        if (!vis[i])
            topoSort(vis, adj, i, stk);
    }
    while (stk.size() > 0)
    {
        cout << stk.top() << "   ";
        stk.pop();
    }

    return 0;
}