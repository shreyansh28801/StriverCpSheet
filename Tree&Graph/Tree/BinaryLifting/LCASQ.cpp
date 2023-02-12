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
Problem Link => https://www.spoj.com/problems/LCASQ/
*/

const ll MAX_N = 1e4 ;
const ll LOG = 14;

vector<ll> adj[MAX_N];
ll up[MAX_N][LOG]; //up[v][j] denotes the 2^jth ancestor of v
ll depth[MAX_N];

void dfs(ll node)
{
    for (ll neigh : adj[node])
    {
        depth[neigh] = depth[node] + 1;
        up[neigh][0] = node;
        for (ll j = 1; j < LOG; j++)
        {
            up[neigh][j] = up[ up[neigh][j - 1] ][j - 1];
        }
        dfs(neigh);
    }
    return;
}

ll getLCA_BruteForce(ll a, ll b)
//T.C => O(N)
{
    if (depth[a] < depth[b])
        swap(a, b);

    while (depth[a] > depth[b])
    {
        a = up[a][0]; //it is same as a=parent(a)
    }

    while (a != b)
    {
        a = up[a][0];
        b = up[b][0];
    }
    return a;
}


ll getLCA_Optimized(ll a, ll b)
//T.C => O(N)
{
    if (depth[a] < depth[b])
        swap(a, b);


    //first we have to take a and be in same level
    ll k=depth[a]-depth[b];


    for (ll j = LOG-1; j >=0 ; j--)
    {
        if(k&(1<<j)){
            a=up[a][j]; // parent of a
        }
    }

    //  if b was ancestor of a then now a==b
    if(a==b)return a;

    //  move both a and b with powers of two
    for (int j = LOG - 1; j >= 0; j--)
    {
        if(up[a][j]!=up[b][j]){
            a=up[a][j];
            b=up[b][j];
        }
    }
    
    return up[a][0];
}

void solve()
{
    ll n;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll m;
        cin >> m;
        for (ll j = 0; j < m; j++)
        {
            ll x;
            cin >> x;
            adj[i].push_back(x);
        }
    }

    //given in the Question => The root of the tree will always be node 0.
    // since up[0] is  a global vector hence we need not to assign value of magical line (by convention to avoid over lifting we have decided to use magical line basically any 2^jth  ancestor of root is root itself.

    dfs(0);

    ll q;
    cin >> q;
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        cout << getLCA_Optimized(a, b) << nl;
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
    t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}