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
typedef long double ld;

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

int totalFruit(vector<int> &fruits)
{
    int i = 0;
    int j = 0;
    int ans = 0;
    int n = fruits.size();
    unordered_map<int, int> ump;
    while (j < n)
    {
        ump[fruits[j]]++;
        if (ump.size() < 2)
            j++;
        else if (ump.size() == 2)
        {
            ans = max(ans, (j - i + 1));
            j++;
        }
        else
        {
            while (ump.size() > 2)
            {
                ump[fruits[i]]--;
                if (ump[fruits[i]] == 0)
                    ump.erase(fruits[i]);
                i++;
            }
            ans = max(ans, (j - i + 1));
            j++;
        }
    }
    return ans;
}

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