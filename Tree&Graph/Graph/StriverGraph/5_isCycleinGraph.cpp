#include <bits/stdc++.h>
using namespace std;

class isCycleInGraph_UsingBfs
{
private:
    /* data */
    bool helperfun(int node, vector<bool> &vis, vector<int> adj[])
    {
        queue<pair<int, int>> q_pr;
        q_pr.push({node, -1});
        vis[node] = 1;
        while (!q_pr.empty())
        {
            int data = q_pr.front().first;
            int parent = q_pr.front().second;
            q_pr.pop();
            for (int it : adj[data])
            {
                if (!vis[it])
                {
                    q_pr.push({it, data});
                    vis[it] = 1;
                }
                else if (it != parent)
                {
                    return 1;
                }
            }
        }
        return 0;
    }

public:
    bool isCyclePresent(vector<int> adj[], int n)
    {
        vector<bool> vis(n + 1, 0);
        for (int i = 1; i < n + 1; i++)
        {
            if (!vis[i])
            {
                bool ans = helperfun(i, vis, adj);
                if (ans)
                    return true;
            }
        }
        return false;
    }
};

class isCycleInGraph_UsingDfs
{
private:
    /* data */
    bool helperfun(int node, int parent, vector<bool> &vis, vector<int> adj[])
    {
        vis[node] = 1;
        for (int it : adj[node])
        {
            if (!vis[it])
            {
                if (helperfun(it, node, vis, adj))
                    return true;
            }
            else if (it != parent)
            {
                return true;
            }
        }
        return 0;
    }

public:
    bool isCyclePresent(vector<int> adj[], int n)
    {
        vector<bool> vis(n + 1, 0);
        for (int i = 1; i < n + 1; i++)
        {
            if (!vis[i])
            {
                bool ans = helperfun(i, -1, vis, adj);
                if (ans)
                    return true;
            }
        }
        return false;
    }
};

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

    isCycleInGraph_UsingDfs o1;
    cout << o1.isCyclePresent(adj, n);

    return 0;
}