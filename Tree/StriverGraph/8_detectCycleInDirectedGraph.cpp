#include <bits/stdc++.h>
using namespace std;

class isCycleInDirGraph_UsingDfs
{
private:
    /* data */
    bool helperfun(int node, int parent, vector<bool> &vis,vector<bool> &dfsVis, vector<int> adj[])
    {
        vis[node] = 1;
        dfsVis[node] = 1;
        for (int it : adj[node])
        {
            if (!vis[it])
            {
                if (helperfun(it, node, vis, dfsVis ,adj))
                    return true;
            }
            else if (it != parent && dfsVis[it]==1)
            {
                return true;
            }


            //Assume only one direction is linked b/w 2 nodes . That's why we don't need to consider condition of it!= parent bcz we node we know considering above condition that there will be no link from it to node.



            // else if (it != parent && dfsVis[it]==1)
            // {
            //     return true;
            // }
        }
        dfsVis[node]=0;
        return 0;
    }

public:
    bool isCyclePresent(vector<int> adj[], int n)
    {
        vector<bool> vis(n + 1, 0);
        vector<bool> dfsVis(n + 1, 0);
        for (int i = 1; i < n + 1; i++)
        {
            if (!vis[i])
            {
                bool ans = helperfun(i, -1, vis, dfsVis ,adj);
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

    return 0;
}