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
    int n, q;
    cin >> n >> q;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        v[i] = str;
    }

    vector<vector<ll>> prefixSum(n, vector<ll>(n, 0));
    prefixSum[0][0]=('*'==v[0][0]);

    for (int i = 1; i < n; i++)
    {
        if (v[0][i] == '*')
            prefixSum[0][i] = 1+prefixSum[0][i-1];
        else prefixSum[0][i]=prefixSum[0][i-1];
    }
    for (int i = 1; i < n; i++)
    {
        if (v[i][0] == '*')
            prefixSum[i][0] = 1+prefixSum[i-1][0];
        else prefixSum[i][0]=prefixSum[i-1][0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (v[i][j] == '*')
                prefixSum[i][j] = 1 + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
            else 
                prefixSum[i][j] =  prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
        }
    }
    // for (auto i : prefixSum)
    // {
    //     cout << i << nl;
    // }

    function<ll(ll,ll)> query = [&](ll x,ll y){
        if(x<0||y<0)    return 0ll;
        else {
            return prefixSum[x][y];
        }
    };

    while (q--)
    {
        int y1, x1, y2, x2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << query(x2-1,y2-1) - query(x1 - 2,y2 - 1) - query(x2 - 1,y1 - 2) + query(x1 - 2,y1 - 2) << nl;
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
        // cout<<"fkjdkl";
        solve();
    }
    return 0;
}