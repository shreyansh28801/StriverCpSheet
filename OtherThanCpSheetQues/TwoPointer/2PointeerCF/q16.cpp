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

https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/A

*/

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<ll> v(N_local);
    */

    int n, s;
    cin >> n >> s;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        v.pub(x);
    }
    int lptr=0;
    int rptr=0;
    int s1=0;
    int ans=0;
    while (rptr<n)
    {
        // cout<<lptr<<"   "<<rptr<<endl;
        s1+=v[rptr];
        if(s1<=s){
            ans=max(ans,(rptr-lptr)+1);
            rptr++;
        }
        else{
            // ans=max(ans,(rptr-lptr));
            while (s1>s&&lptr<=rptr)
            {
                s1-=v[lptr];
                lptr++;
            }
            rptr++;
            
        }
    }
    // cout<<lptr<<"  "<<rptr<<"  " <<ans<<endl;

    ans=max(ans,(rptr-lptr));
    cout<<ans;
    
    

    return 0;
}