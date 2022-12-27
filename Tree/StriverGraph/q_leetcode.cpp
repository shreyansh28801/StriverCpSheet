#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long int li;
typedef long double ld;
#define lb lower_bound
#define ub upper_bound
#define pub push_back
#define pob pop_back
typedef long double ld;

/*

You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

Return the number of pairs of different nodes that are unreachable from each other.


*/

class Solution
{

    int bfs(vector<int> adj[], vector<bool> &visited, int node)
    {

        queue<int> q;
        q.push(node);
        visited[node] = 1;
        int ct = 0;
        while (!q.empty())
        {
            int d = q.front();
            ct++;

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

public:
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        vector<int> adj[n + 1]; //assuming 1 base indexing of nodes

        //next e lines has edeges details;
        for (int i = 0; i < edges.size(); i++)
        {
            int u, v;
            u = edges[i][0];
            v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> vis(n + 1, 0);
        
        vector<int> ans;
        for (int i = 1; i < n + 1; i++)
        {
            if (!vis[i])
            {
                int temp = bfs(adj, vis, i);
                ans.push_back(temp);
            }
        }
        if(ans.size()==1) return 0;
        ll res = 0;
        ll sum = accumulate(ans.begin(), ans.end(), 0);
        for (int i = 0; i < ans.size(); i++)
        {
            res += ((sum - ans[i]) * 1ll * ans[i]);
        }
        return res/2;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<int> v(N_local);
    */

    return 0;
}