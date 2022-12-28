#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long int li;
#define int long long int
typedef long double ld;
#define lb lower_bound
#define ub upper_bound
#define pub push_back
#define pob pop_back
#define nl "\n"
typedef long double ld;

template <typename T>
istream &operator>>(istream &input, vector<T> &v)
{
    for (auto &i : v)
        cin >> i;
    return input;
}

template <typename T>
ostream &operator<<(ostream &output, vector<T> &v)
{
    for (auto &i : v)
        cout << i << " ";
    return output;
}

//Definition of custom hash function to avoid collision in malicious test-cases (aka hacked test-cases)

struct cstH
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

//Now we can simply define our unordered_map or our gp_hash_table as follows:
//unordered_map<long long, int, cstH> safe_map;
//gp_hash_table<long long, int, cstH> safe_hashtable;

int M = 1e9 + 7;

/*

const int N = 1e6+10 ;
vector<ll> A(N) ;




void solve(){
    

}
*/

void dfs(vector<int> adj[], vector<bool> &vis, int node, vector<int> &ans)
{
    vis[node] = 1;
    ans.push_back(node);

    //traversing all its neighbours
    for (auto it : adj[node])
    {
        string str;
        cin>>str;
        cout<<"hi  "<<it;
        if (!vis[it])
        {
            dfs(adj, vis, node, ans);
            // vis[it]=1;
        }
    }
    return;
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<bool> vis(V, 0);
    vector<int> ans;
    int start = 0;

    dfs(adj, vis, start, ans);
    return ans;
}

int32_t main()
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

    ll k=0;

    for(auto i:adj){
        cout<<k<<"   ";
        for(int j:i)cout<<j<<" ";
        cout<<nl;
        k++;
    }

    cout<<"hello\n";
    // vector<int> ans=dfsOfGraph(n,adj);
    //cout<<ans.size()<<nl;
    // cout<<ans<<nl;
    return 0;
}