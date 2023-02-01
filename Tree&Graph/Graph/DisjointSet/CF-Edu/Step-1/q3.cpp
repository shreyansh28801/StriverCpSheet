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

class DisjointSet
{
private:
    /* data */
    vector<ll> size;
    vector<ll> parent;
    vector<vector<ll>> List;  //list[i] denotes collection of all nodes under the leadership of i.
    vector<ll> pendingPoints; //if i is the leader of group then pendingPoints[i] denotes the points yet to be propagated to all its other member of group
    vector<ll> currentPoints;

public:
    DisjointSet(int n)
    {
        size.resize(n, 1);
        parent.resize(n);
        pendingPoints.resize(n, 0);
        currentPoints.resize(n, 0);
        List.resize(n);

        for (ll i = 0; i < n; i++)
        {
            parent[i] = i;
            List[i].push_back(i);
        }
    }
    ll getParent(ll node)
    {
        return parent[node] = (parent[node] == node ? node : getParent(parent[node]));
    }

    void merge(ll u, ll v)
    //u and v are merged undeer the leadership of u
    {
        for (ll j : List[v])
        {
            currentPoints[j] += (pendingPoints[v] - pendingPoints[u]);
        }
        
        for (ll j : List[v])
        {
            List[u].push_back(j);
        }
        List[v].clear();
    }

    void unionBySize(ll u, ll v)
    {
        ll ul_pu = getParent(u);
        ll ul_pv = getParent(v);

        if (ul_pu == ul_pv)
            return;

        if (size[ul_pu] < size[ul_pv])
        {
            merge(ul_pv,ul_pu);
            parent[ul_pu] = ul_pv;
            size[ul_pv] += size[ul_pu];
        }
        else
        {
            merge(ul_pu,ul_pv);
            parent[ul_pv] = ul_pu;
            size[ul_pu] += size[ul_pv];
        }
        // cout<<parent<<nl;
    }
    void add(ll x, ll val)
    {
        pendingPoints[getParent(x)]+=val;
    }
    ll get(ll x)
    {
        // cout<<"woei\n";
        return currentPoints[x]+pendingPoints[getParent(x)];
    }
};

void solve()
{
    ll n, m;
    cin >> n >> m;
   
    DisjointSet ds(n + 1);
    while (m--)
    {
        string s;
        cin >> s;
    
        if (s == "add")
        {
            ll a, b;
            cin >> a >> b;
            ds.add(a, b);
            // cout<<1<<nl;
        }
        else if (s == "get")
        {
            ll a;
            cin >> a;
            cout<<ds.get(a)<<nl;
            // cout<<2<<nl;
        }
        else
        {
            ll a, b;
            cin >> a >> b;
            ds.unionBySize(a, b);
            // cout<<3<<nl;
        }
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