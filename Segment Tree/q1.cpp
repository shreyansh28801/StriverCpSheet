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
    vector<ll> v(1 << n);
    cin >> v;
    ll n1 = n;

    //no preprocessing required here bcz already n is power of 2

    //build up of seg tree
    vector<ll> segTree(2 * (1 << n));
    n = (1 << n);
    for (int i = n; i < 2 * n; i++)
    {
        segTree[i] = v[i - n];
    }
    int temp = __builtin_clzl(n);
    // cout << n << "  temp is  " << temp << nl;
    for (int i = n - 1; i >= 1; i--)
    {
        // cout << __builtin_clzl(i) << "  " << i << nl;
        if (__builtin_clzl(i) % 2 != temp % 2)
        {
            segTree[i] = segTree[2 * i] | segTree[(2 * i) + 1];
        }
        else
            segTree[i] = segTree[2 * i] ^ segTree[(2 * i) + 1];
    }

    // cout << segTree << nl;

    //updation function

    function<ll(ll, ll)> update = [&](ll pos, ll val)
    {
        segTree[pos - 1 + n] = val;

        for (int i = (pos - 1 + n) / 2; i >= 1; i /= 2)
        {
            if (__builtin_clz(i) % 2 != temp % 2)
                segTree[i] = segTree[2 * i] | segTree[(2 * i) + 1];
            else
                segTree[i] = segTree[2 * i] ^ segTree[(2 * i) + 1];
        }

        return segTree[1];
    };

    while (m--)
    {
        int a,b;
        cin>>a>>b;
        cout<<update(a,b)<<nl;
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