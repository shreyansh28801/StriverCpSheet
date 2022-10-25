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
    string str;
    cin >> str;
    int q;
    cin >> q;
    int n = str.size();
    vector<int> ans(n);
    if (str[0] == str[1])
        ans[0] = 1;
    else
        ans[0] = 0;
    for (int i = 1; i < n - 1; i++)
    {
        ans[i] = ans[i - 1];
        if (str[i] == str[i + 1])
        {
            ans[i]++;
        }
    }
    // for (int i : ans)
    //     cout << i << " ";
    // cout << " arr finished" << nl;

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if (l == 1)
        {
            // cout << (r - 2) << "  " << ans[r - 2] << nl;
            cout << ans[r - 2] << nl;
        }
        else
        {
            // cout << (r - 2) << "  " << ans[r - 2] << "  " << l << " " << ans[l - 2] << nl;
            cout << (ans[r - 2] - ans[l - 2]) << nl;
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