#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //let's assume we have adjacency list of graph
    int n;//n is number of edeges
    vector<bool> visited(n+1,0);//intially each node is marked as unvisited (false).
    
    int ct=0;//ct denotes the count of different connected components of given graph

    for (int i = 0; i < n+1; i++)
    {
        if(!visited[i])  {
            // aplly bfs or dfs and mark each node 1(true) on   travesing a node
            ct++;          
        }
    }
    cout<<"the no. of diiferent connected components in graph is is  :"<<ct<<"\n";
    

    return 0;
}