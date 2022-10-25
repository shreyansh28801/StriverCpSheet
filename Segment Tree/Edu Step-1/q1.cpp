#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long int li;
typedef long double ld;
#define lb lower_bound
#define ub upper_bound
#define pub push_back
#define pob pop_back
#define nl endl
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
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    cin >> v;

    //pre proceasing of segment tree

    while (__builtin_popcountll(n) != 1)
    {
        n++;
        v.pub(0);
    }

    //building of segment tree

    vector<ll> segTree(2 * n);
    for (ll i = n; i < 2 * n; i++)
    {
        segTree[i] = v[i - n];
    }
    for (ll i = n - 1; i > 0; i--)
    {
        segTree[i] = segTree[2 * i] + segTree[(2 * i) + 1];
    }

    // cout << segTree;

    //updation function of segment tree

    function<void(ll, ll)> upadte = [&](ll pos, ll val)
    //suppose pos is w.r.t. 0 base indexing of v.
    {
        segTree[pos + n] = val;
        for (ll j = (pos + n) / 2; j >= 1; j /= 2)
        {
            segTree[j] = segTree[j * 2] + segTree[(j * 2) + 1];
        }
    };

    //query function of Segment tree
    function<ll(ll, ll, ll, ll, ll)> query = [&](ll node, ll lx, ll rx, ll l, ll r)
    //suppose l,r are w.r.t. 0 base indexing of v.
    {
        if (l > rx || r < lx)
            return 0ll;
        if (l<= lx && r >= rx)
            return segTree[node];

        ll mid=(lx+rx)/2;
        ll a=query(node*2,lx,mid,l,r);
        ll b=query((node*2)+1,mid+1,rx,l,r);
        return a+b;
        
    };

    while (m--)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        if(1==a){
            upadte(b,c);

        }
        else {
            cout<<query(1,0,n-1,b,c-1)<<nl;
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
    solve();

    return 0;
}