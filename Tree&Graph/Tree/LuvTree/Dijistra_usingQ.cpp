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

problem link => https://leetcode.com/problems/network-delay-time/description/

Using queue brute force like implementation
*/

class Solution
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<pair<int, int>> adj[n + 1];
        for (auto v : times)
        {
            adj[v[0]].push_back({v[1], v[2]});
        }

        vector<int> cost(n + 1, INT_MAX);

        queue<pair<int,int>> q;
        q.push({0, k});
        cost[k] = 0;
        while (!q.empty())
        {
            int u = q.front().second;
            q.pop();
            for (auto j : adj[u])
            {
                int v = j.first;
                int wt = j.second;

                if (cost[v] > (cost[u] + wt))
                {
                    cost[v] = cost[u] + wt;
                    q.push({cost[v], v});
                }
            }
        }

        int ans = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            ans = max(ans, cost[i]);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<ll> v(N_local);
    */
    
    return 0;
}