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

/*

https://cses.fi/problemset/task/1135
*/

const ll MAX_N = 2e5 + 10;
const ll LOG = 20;

vector<vector<ll>> adj(MAX_N);
vector<ll> depth(MAX_N);
ll up[MAX_N][LOG];
// vector<ll> par(MAX_N);

vector<int> findPar(int root, int n)
{
    queue<int> q;
    vector<ll> par(n);
    q.push(root);
    vector<int> vis(adj.size(), 0);
    par[root] = -1;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        vis[f] = 1;
        for (int neigh : adj[f])
        {
            if (vis[neigh] == 0)
            {
                q.push(neigh);
                par[neigh] = f;
            }
        }
    }
    // cout<<"parent vector is "<<endl;
    // for(int i=0;i<adj.size();i++)cout<<par[i]<<" ";
    return par;
}

void dfs(ll node, ll par)
// Binary Lifting Preprocessing
{
    // cout<<node<<" aoifjd ";
    for (ll neigh : adj[node])
    {
        if (neigh != par)
        {
            depth[neigh] = depth[node] + 1;
            up[neigh][0] = node;
            for (ll j = 1; j < LOG; j++)
            {
                up[neigh][j] = up[up[neigh][j - 1]][j - 1];
            }
            dfs(neigh, node);
        }
    }
    return;
}

ll getDistance(ll a, ll b)
{
    // cout<<a<<" "<<b<<nl;
    ll ans = 0;
    if (depth[a] < depth[b])
        swap(a, b);

    ll k = depth[a] - depth[b];
    ans += k;

    for (ll i = 0; i < LOG; i++)
    {
        if (k & (1 << i))
        {
            a = up[a][i];
        }
    }

    // cout<<"tempo ans is "<<ans<<nl;

    //  if b was ancestor of a then now a==b
    if (a == b)
        return ans;

    //  move both a and b with powers of two
    for (int j = LOG - 1; j >= 0; j--)
    {
        if (up[a][j] != up[b][j])
        {

            ans += (1 << j)*2;
            a = up[a][j];
            b = up[b][j];
            // cout<<j<<" j is "<<ans<<" " <<a<<b<<nl;
        }
    }
    if (a != b && (up[a][0] == up[b][0]))
        ans += 2;

    return ans;
}

void dfs_setDepth(int node, int par)
{
    if (par != -1)
        depth[node] = depth[par] + 1;
    for (auto neigh : adj[node])
    {
        if (neigh != par)
            dfs_setDepth(neigh, node);
    }
    return;
}

void solve()
{
    ll n, q;
    cin >> n >> q;

    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    // for (ll i = 0; i < n; i++)
    // {
    //     cout<<i<<" : ";
    //     for(auto it:adj[i])cout<<it<<" ";
    //     cout<<nl;
    // }
    
    // dfs(0, -1);

    dfs_setDepth(0,-1);
  
    

    vector<ll> parent = findPar(0, n);
    parent[0] = 0;

    for (ll i = 0; i < n; i++)
    {
        up[i][0] = parent[i];
    }
    for (ll j = 1; j < LOG; j++)
    {
        for (ll v = 0; v < n; v++)
        {
            up[v][j] = up[up[v][j - 1]][j - 1];
        }
    }

    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        cout<< getDistance(a-1, b-1) << nl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<ll> v(N_local);
    */
    int t;
    t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}