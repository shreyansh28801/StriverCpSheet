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

bool LCA(vector<ll> adj[], ll a, ll b, ll node, ll par, ll &ans)
{
    cout << node << "  " << par << nl;

    ll ct = 0;
    if (node == a || node == b)
    {
        ct++;
    }
    for (int j : adj[node])
    {
        if (j != par)
        {
            bool b1 = LCA(adj, a, b, j, node, ans);
            if (b1 == 1)
                ct++;
        }
    }
    if (2 == ct)
        ans = node;
    if (ct > 0)
        return 1;
    else
        return 0;
}

bool root2NodePath(vector<ll> adj[], ll target, ll node, ll par, vector<ll> &path)
{

    if (node == target)
    {
        path.push_back(node);
        return 1;
    }

    for (ll j : adj[node])
    {
        if (j != par)
        {
            if (root2NodePath(adj, target, j, node, path))
            {
                path.push_back(node);
                return 1;
            }
        }
    }
    return 0;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> adj[n + 1];
    for (ll j = 0; j < n - 1; j++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    /*
    1st method to find lca

    ll ans = -1;
    ll temp = LCA(adj, 8, 5, 1, -1, ans);
    cout << ans << nl;
    */

    /*
    2nd method to find lca using path comparision

    ll a, b;
    cin >> a >> b;

    vector<ll> path1;
    root2NodePath(adj, a, 1, -1, path1);
    vector<ll> path2;
    root2NodePath(adj, b, 1, -1, path2);

    reverse(path1.begin(),path1.end());
    reverse(path2.begin(),path2.end());

    cout<<path1<<nl<<path2<<nl;
    int sz=min(path1.size(),path2.size());
    ll j=0;
    for( ;j<sz;j++){
        if(path1[j]!=path2[j])break;
    }
    
    cout<<"LCA of "<<a<<" and "<<b<<" is : " <<path1[j-1]<<nl;
    */

   /*
   3rd method - first construct a mapining of node to parent using bfs or dfs
   then easily we can store the path of the  bothtarget  nodes but it will be in reverse order w.r.t. root to node.
   now applying same concept as in method 2 for path1 and path2
   */
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
    // t=1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}