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

struct cstH {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

//Now we can simply define our unordered_map or our gp_hash_table as follows:
//unordered_map<long long, int, cstH> safe_map;
//gp_hash_table<long long, int, cstH> safe_hashtable;

int M=1e9+7;

/*

const int N = 1e6+10 ;
vector<ll> A(N) ;


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
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        string str;
        cin>>str;
        int s=0,e=0;
        unordered_map<char,int> ump;
        ump['W']=0;
        ump['B']=0;
        int ans=1e9+7;

        while (e<n)
        {
            ump[str[e]]++;
            if((e-s+1)<k)  e++;
            else if((e-s+1)==k) {
                ans=min(ans,k-ump['B']);
                e++;

            }   
            else{
                while((e-s+1)>k){
                    ump[str[s]]--;
                    s++;
                }
                 ans=min(ans,k-ump['B']);
                e++;
            }

        }
        cout<<ans<<endl;
        
    }
    



    return 0;
}