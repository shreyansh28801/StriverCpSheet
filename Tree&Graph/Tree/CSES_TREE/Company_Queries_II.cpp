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


*/

const ll N = 2e5 + 3;
const ll Log = 20;
vector<vector<ll>> adj;
ll up[N][Log];
vector<ll> depth;

void dfs(ll node, ll par, vector<ll> &parent)
{
    // cout<<node<<" "<<par<<nl;
    for (auto it : adj[node])
    {
        if (par != it)
        {
            parent[it] = node;
            depth[it] = depth[node] + 1;
            dfs(it, node, parent);
        }
    }
}

ll query( ll a,ll b,vector<ll> &parent)
{
    if(depth[a]<depth[b])swap(a,b);
    // cout<<depth[a]<<" "<<depth[b]<<nl;
    ll k=depth[a]-depth[b];

    for (ll j = 0; j < Log; j++)
    {
        if(k&(1<<j))a=up[a][j];
    }
    if(a==b)return a;
    for (int i = Log - 1; i >= 0; i--)
    {
        if(up[a][i]==up[b][i])continue;
        a=up[a][i];
        b=up[b][i];
    }
    return parent[a];
    
   
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> v(n - 1);
    cin >> v;

    adj.resize(n);

    for (ll i = 0; i < n - 1; i++)
    {
        adj[v[i] - 1].push_back(i + 1);
        // adj[i].push_back(v[i] - 1);
    }

    depth.resize(n);
    depth[0] = 0;

    vector<ll> parent(n);
    parent[0] = 0;

    dfs(0, -1, parent);
    // cout<<parent<<nl;
    // cout << depth << nl;

    for (ll i = 0; i < n; i++)
    {
        up[i][0] = parent[i];
    }

    for (ll j = 1; j < Log; j++)
    {
        for (ll v = 0; v < n; v++)
        {
            up[v][j] = up[up[v][j - 1]][j - 1];
        }
    }

    while (q--)
    {
      ll a,b;
      cin>>a>>b;

      cout<<1+query(a-1,b-1,parent)<<nl;;
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
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}