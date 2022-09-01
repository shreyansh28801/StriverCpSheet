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

Ques Link => https://codeforces.com/problemset/problem/1691/B

*/

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
        map<int, vector<int>> mv;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            mv[x].pub(i+1);
        }
        int flag = 0;
        for (auto v : mv)
        {
            if (v.second.size() == 1)
            {
                flag = -1;
                break;
            }
        }
        if (0 != flag)
        {
            cout << "-1\n";
        }
        else
        {
            for (auto v : mv)
            {

                auto it = --(v.second.end());
                auto fP = v.second.begin();
                if(v.second.size()%2==1){
                    int temp=v.second[v.second.size()/2];
                    v.second[v.second.size()/2]=v.second[0];
                    v.second[0]=temp;
                }

                while (it != fP)
                {
                    cout << *it << " ";
                    it--;
                }
                cout<<(*it)<<endl;
            }
        }
    }

    return 0;
}