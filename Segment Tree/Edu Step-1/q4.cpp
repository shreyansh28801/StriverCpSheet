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

struct segmentTreeNode
{
    ll val;  //denotes max sum value  in its node range
    ll pref; //max prefix sum in node's range
    ll suf;  //max suffix value in  node's range
    ll sum;  //sum in the range
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> v(n);
    cin >> v;
    //pre processing
    while (__builtin_popcount(n) != 1)
    {
        n++;
        v.pub(0);
    }

    ////building of  seg tree
    vector<segmentTreeNode> segTree(2 * n);
    for (int i = n; i < 2 * n; i++)
    {
        segTree[i].val = v[i - n];
        segTree[i].pref = v[i - n];
        segTree[i].suf = v[i - n];
        segTree[i].sum = v[i - n];
    }
    for (int i = n - 1; i > 0; i--)
    {
        segTree[i].pref = max(max(segTree[2 * i].pref, 0ll), segTree[(2 * i)].sum + segTree[(2 * i) + 1].pref);
        segTree[i].suf = max(max(segTree[(2 * i) + 1].suf, 0ll), segTree[2 * i].suf + segTree[(2 * i) + 1].sum);
        segTree[i].val = max((segTree[2 * i].suf + segTree[(2 * i) + 1].pref), max(segTree[i * 2].val, segTree[(2 * i) + 1].val));
        segTree[i].sum = segTree[2 * i].sum + segTree[(2 * i) + 1].sum;
    }

    // for (auto i : segTree)
    //     cout << i.val << " " << i.pref << " " << i.suf << "  " << i.sum << nl;

    //updation function
    function<void(ll, ll)> update = [&](ll pos, ll val)
    {
        segTree[pos + n].val = val;
        segTree[pos + n].pref = val;
        segTree[pos + n].suf = val;
        segTree[pos + n].sum = val;

        for (ll i = (pos + n) / 2; i >= 1; i /= 2)
        {
            segTree[i].pref = max(max(segTree[2 * i].pref, 0ll), segTree[(2 * i)].sum + segTree[(2 * i) + 1].pref);
            segTree[i].suf = max(max(segTree[(2 * i) + 1].suf, 0ll), segTree[2 * i].suf + segTree[(2 * i) + 1].sum);
            segTree[i].val = max((segTree[2 * i].suf + segTree[(2 * i) + 1].pref), max(segTree[i * 2].val, segTree[(2 * i) + 1].val));
            segTree[i].sum = segTree[2 * i].sum + segTree[(2 * i) + 1].sum;
        }
    };

    //query for max sum segment

    cout << max(segTree[1].val, 0ll) << nl;
    //addresiing query
    while (m--)
    {
        int pos, val;
        cin >> pos >> val;

        update(pos, val);
        // cout << "after up :" << nl;
        // for (auto i : segTree)
        //     cout << i.val << " " << i.pref << " " << i.suf << "  " << i.sum << nl;
        // if(segTree[1].maxBelowThis<0)   cout<<0<<nl;

        // else cout << segTree[1].maxBelowThis << nl;

        ll ans = max(0ll, segTree[1].val);
        cout << ans << nl;
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