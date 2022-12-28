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
    string s, d;
    cin >> s >> d;

    if(s==d){cout<<0<<nl;return ;}

    pair<ll, ll> src = {(s[0] - 'a'), (s[1] - '1')};
    pair<ll, ll> des = {(d[0] - 'a'), (d[1] - '1')};

    queue<pair<pair<ll, ll>, ll>> q;

    vector<vector<bool>> vis(8, vector<bool>(8, 0));

    q.push({src, 0});
    vector<ll> delRow = {-2, 2, -2, 2, 1, 1, -1, -1};
    vector<ll> delCol = {1, 1, -1, -1, -2, 2, -2, 2};
    vis[src.first][src.second] = 1;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        auto curCell = it.first;
        ll level = it.second;
        bool fl=0;

        for (ll j = 0; j < 8; j++)
        {
            ll nR = curCell.first + delRow[j];
            ll nC = curCell.second + delCol[j];

            if (nR >= 0 && nR < 8 && nC >= 0 && nC < 8 && vis[nR][nC] == 0)
            {
                vis[nR][nC] = 1;
                if (nR == des.first && nC == des.second)
                {
                    cout << level + 1 << nl;
                    fl = 1;
                    break;
                }
                q.push({{nR, nC}, level + 1});
            }
        }
        if(1==fl){
            break;
        }
    }
    return;
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