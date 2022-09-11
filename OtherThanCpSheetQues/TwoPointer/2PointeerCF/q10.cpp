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

//This function  checks if we ignore an elemement "ignore" then will array be palindrome??
bool isPalindromeVector(vector<int> &v, int &ignore)
{

    int s = 0;
    int e = v.size() - 1;

    while (s < e)
    {
        if (v[s] != v[e])
        {
            if (v[s] != ignore && v[e] != ignore)
                return false;
            else if (v[s] == ignore)
                s++;
            else
                e--;
        }
        else
        {
            s++;
            e--;
        }
    }
    return true;
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
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.pub(x);
        }
        bool f=0;
        for (int i = 0; i < (n / 2); i++)
        {
            if (v[i] != v[n - 1 - i])
            {
                if (isPalindromeVector(v, v[i]) || isPalindromeVector(v, v[n - 1 - i]))
                {
                    cout << "YES\n";
                }
                else
                {
                    cout << "NO\n";
                }
                f=1;
                break;
            }
        }
        if(0==f)    cout<<"YES\n";
    }

    return 0;
}