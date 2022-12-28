#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define mod 1000000007
#define endl "\n"
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

void dfs(vector<int> adj[], int V, vector<bool> &vis, int node, vector<int> &ans)
{
    vis[node] = true;
    ans.push_back(node);

    for (int i = 0; i < vis.size(); i++)
        cout << vis[i] << " ";
    cout << endl;

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    cout << endl;
    if (node == 2)
        return;

    // traversing all its neighbours
    // for (int i = 0; i < adj[node].size(); i++)
    // {
    //     if (!vis[adj[node][i]])
    //     {
    //         cout << "HI";
    //         dfs(adj, vis, node, ans);
    //     }
    // }
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            // cout << it << endl;
            // return;
            dfs(adj, V, vis, node, ans);
        }
    }
    return;
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<bool> vis(V, false);
    vector<int> ans;
    int start = 0;
    dfs(adj, V, vis, start, ans);
    return ans;
}

int32_t main()
{
    fio;
    int n, e; // n,e denotes no. of nodes and edeges respectively
    cin >> n >> e;
    vector<int> adj[n];
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> v = dfsOfGraph(n, adj);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return 0;
}