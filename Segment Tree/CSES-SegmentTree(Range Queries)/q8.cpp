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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> h(n);
    cin >> h;
    vector<ll> g(m);
    cin >> g;
    // cout<<n<<"  "<<m<<nl;
    // cout<<h<<nl;
    // cout<<g<<nl;

    //preprocessing
    while (__builtin_popcount(n) != 1)
    {
        n++;
        h.push_back(INT_MIN);
    }
    ////building of  seg tree

    vector<ll> segTree(2 * n);
    for (int i = n; i < 2 * n; i++)
    {
        segTree[i] = h[i - n];
    }
    for (int i = n - 1; i > 0; i--)
    {
        segTree[i] = max(segTree[2 * i], segTree[(2 * i) + 1]);
    }
    // cout << segTree << nl;

    // //update function
    // function<void(ll, ll)> update = [&](ll pos, ll val)
    // {
    //     segTree[pos] -= val;
    //     if(segTree[pos]==0) segTree[pos]=INT_MIN;
    //     for (int i = (n + pos) / 2; i >= 1; i /= 2)
    //     {
    //         segTree[i] = max(segTree[2 * i], segTree[(2 * i) + 1]);
    //     }
    // };

    //query function returns the node(hotel no.) from which rooms are given
    function<ll(ll, ll, ll, ll)> query = [&](ll node, ll lx, ll rx, ll val)
    {
        // cout << node << " " << lx << " " << rx << "  " << val << nl;
        if (segTree[node] < val)
            return 0ll;
        if (lx == rx)
            return node;
        ll mid = (lx + rx) / 2;
        if (segTree[2 * node] >= val)
            return query(2 * node, lx, mid, val);
        else
            return query((2 * node) + 1, mid + 1, rx, val);
    };

    //addressing query stored in g
    for (int i = 0; i < m; i++)
    {
        ll pos = query(1, 0, n - 1, g[i]);
        if (pos != 0)
        {
            cout << (pos + 1 - n) << " ";

            //updateing segtrree
            segTree[pos] -= g[i];
            for (int i = ( pos) / 2; i >= 1; i /= 2)
            {
                segTree[i] = max(segTree[2 * i], segTree[(2 * i) + 1]);
            }
        }
        else
            cout << 0 << " ";
    }

    /*
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
    t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}