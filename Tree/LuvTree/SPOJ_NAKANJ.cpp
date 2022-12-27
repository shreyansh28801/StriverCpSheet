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
    string src, des;
    cin >> src >> des;

    pair<ll, ll> pr_s = {(src[0] - 'a'), (src[1] - '1')};
    pair<ll, ll> pr_d = {(des[0] - 'a'), (des[1] - '1')};

    vector<vector<bool>> chess(8, vector<bool>(8, 0));

    queue<pair<pair<int, int>, int>> q;
    q.push({pr_s, 0});
    // cout<<pr_d.first<<pr_d.second<<"   ";
    // cout<<pr_s.first<<pr_s.second<<nl;

    ll ans = 0;
    chess[pr_s.first][pr_s.second]=1;

    // cout<<

    while (!q.empty())
    {
        auto f = q.front();
        q.pop();

        ll cur_R = f.first.first;
        ll cur_C = f.first.second;
        ll level = f.second;

        // cout<<cur_R<<"  "<<cur_R<<nl;
       

        vector<ll> delR = {2, -2, 2, -2,1, 1, -1, -1};
        vector<ll> delC = {1, 1, -1, -1,2, -2, 2, -2};

        bool fl = 0;

        for (ll j = 0; j < 8; j++)
        {
            ll nR = cur_R + delR[j];
            ll nC = cur_C + delC[j];

            if (nR >= 0 && nR < 8 && nC >= 0 && nC < 8 && chess[nR][nC] == 0)
            {
                // cout << nR << "  " << nC << "  " << cur_R << "  " << cur_C << " j " << j<<" "<<level+1 << nl;

                if (pr_d.first==nR && pr_d.second==nC)
                {
                    // ans = level ;
                    cout<<level+1<<"\n";
                    fl = 1;
                    break;
                }
                q.push({{nR, nC}, level + 1});
                chess[nR][nC]=1;
            }
        }
        if (1 == fl)
            break;

       
    }

    // cout << ans << nl;
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