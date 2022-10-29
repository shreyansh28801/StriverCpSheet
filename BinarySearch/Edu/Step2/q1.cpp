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
ll w, h, n;

bool is_side_suitable(ll mid)
{
    ll no_of_rec_wrt_h = (mid / max(w, h));
    ll no_of_rec_wrt_w = (mid / min(w, h));
    ll extra = 0;
    /*

    //if rectanglre can be rotated then we have to consider these extra amount of space for rectangle

    // if (mid % (max(w, h)) >= min(w, h))
    // {
    //     extra += ((mid % (max(w, h))) / min(w, h)) * (no_of_rec_wrt_h);
    // }

    */

    if (no_of_rec_wrt_h >= n & no_of_rec_wrt_w >= 1)
        return 1;
    if (no_of_rec_wrt_w >= n & no_of_rec_wrt_h >= 1)
        return 1;

    return (((no_of_rec_wrt_h * no_of_rec_wrt_w)) >= n);
}

void solve()
{
    cin >> w >> h >> n;

    ll temp = (ll)pow(w * h, 1.0 / 2);
    temp += 1;

    // ll hi = ((ll)pow(n, 1.0 / 2) + 1) * (max(h, w));
    // ll lo = min(min(w, h) * n, (ll)pow(temp * n, 1.0 / 2) );

    ll lo = 1;
    ll hi = max(w, h) * n;
    // ll hi=1e18+10;

    while ((hi - lo) > 1)
    {
        ll mid = (lo + hi) / 2;
        // cout<<hi<<" "<<lo<<"  "<<is_side_suitable(mid) ;
        if (is_side_suitable(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    if (is_side_suitable(lo))
        cout << lo << nl;
    else
        cout << hi << nl;
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