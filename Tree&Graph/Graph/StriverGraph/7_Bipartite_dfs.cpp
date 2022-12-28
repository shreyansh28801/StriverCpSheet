#include <bits/stdc++.h>
using namespace std;

/***
 * 
 * 
 * Definition of bipartite Graph - If a graph can be colored with 2 colors , then it is called bipartite graph .
 * Note - 1. if a graph having odd length then it must not be a bipartite graph. 
 * 
 * 
 * 2 . if a graph  doesn'u  have odd length(it may have even length cycle or simply graph may not have any cycle) then it must be a bipartite graph. 
 * 
 * 
 * 
 * **/


bool isGraphBipartiteUsingDfs(vector<int> adj[], int node, vector<int> &color)
{

    for (int it : adj[node])
    {
        if (color[it] == -1)
        {
            color[it] = 1 - color[node];
            if(!isGraphBipartiteUsingDfs(adj,it, color))    return false;
        }
        else if(color[it]==color[node]) {
            return false;
        }
    }
    return true ;
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

    vector<int> color(n + 1, -1);
    for (int i = 1; i < n + 1; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 0;
            if (!isGraphBipartiteUsingDfs(adj, i, color))
            {

                cout << "Given graph is not bipartite \n";
                break;
            }
        }
    }

    return 0;
}