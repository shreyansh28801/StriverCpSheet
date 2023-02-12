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

ll query(ll n, ll x, ll k)
{
    //T.C. => log(N)
    if (depth[x] < k)
    {
        return -1;
    }
    for (int i = Log; i >= 0; i--)
    {
        if (k & (1 << i))
        {
            x = up[x][i];
        }
    }
    return x;
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
        ll x, k;
        cin >> x >> k;

        ll ans= query(n, x - 1, k);
       if(ans==-1){cout<<-1<<nl;continue;}

        cout << ans + 1 << nl;
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