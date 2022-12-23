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


int dp[200005][2];

ll fu(vector<int> adj[], int node, int isIncluded, int par)
{

    if(dp[node][isIncluded]!=-1)return dp[node][isIncluded];

    ll ans = 0;

    if (!isIncluded)
    {
        for (int i : adj[node])
        {

            // max of including and not including the node i
            if (i != par)
                ans += fu(adj, i, 1, node);
        }
    }
    else
    {
        ll sum_neigb = 0;

        for (int i : adj[node])
        {
            if (i != par)
            {
                sum_neigb += fu(adj, i, 1, node);
            }
        }

        for (int i : adj[node])
        {
            if (i != par)
            {
                ans = max(sum_neigb - fu(adj, i, 1, node) + 1+fu(adj, i, 0, node), ans);
            }
        }

        
    }
    // cout << node << "  " << isIncluded << "  " << ans << nl;

    return dp[node][isIncluded] = ans;
}

void solve()
{
    ll n;
    cin >> n;

    vector<ll> adj[n + 1];
    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(dp,-1,sizeof(dp));

    ll ans1 = fu(adj, 1, 0, -1);

    ll ans2 = fu(adj, 1, 1, -1);

    cout<< max(ans1, ans2) << nl;
    // cout<<ans1<<"  "<<ans2<<"  " << max(ans1, ans2) << nl;
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
