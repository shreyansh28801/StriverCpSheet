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
    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> grid(n, vector<ll>(m));

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            ll x;
            cin >> x;
            grid[i][j] = x;
        }
    }

    //calculating maximum in grid
    ll mx = INT_MIN;

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (grid[i][j] > mx)
                mx = grid[i][j];
        }
    }

    vector<pair<ll, ll>> maxLocation; //positions of all values where maximum exists

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            if (grid[i][j] == mx)
            {
                maxLocation.push_back({i, j});
            }
        }
    }

    queue<pair<pair<ll, ll>, ll>> q;
    for (auto it : maxLocation)
    {
        q.push({it, 0});

    }

    ll ans = 0;


    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        vector<ll> delRow = {1, -1, 1, -1,0,1,0,-1};
        vector<ll> delCol = {1, -1, -1, 1,1,0,-1,0};

        ll level = cur.second;

        ans = max(ans, level);

        

        for (ll i = 0; i < 8; i++)
        {
            ll nR = cur.first.first + delRow[i];
            ll nC = cur.first.second + delCol[i];

            if (nR < n && nR >= 0 && nC >= 0 && nC < m && grid[nR][nC] != mx)
            {
                
                q.push({{nR, nC}, level + 1});
                grid[nR][nC] = mx;
            }
        }
    }
    cout << ans << nl;
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