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
#define nl endl
typedef long double ld;


template <typename T>
istream &operator>>(istream &input, vector<T> &v) {
    for (auto &i : v) cin >> i;
    return input;
}


template <typename T>
ostream &operator<<(ostream &output, vector<T> &v) {
    for (auto &i : v) cout << i<<" ";
    return output;
}


//Definition of custom hash function to avoid collision in malicious test-cases (aka hacked test-cases)

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
        int n;
        cin>>n;
        vector<int> r(n);

        cin>>r;
        int m;
        cin>>m;
        vector<int> b(m);
        cin>>b;


        for (int i = 1; i < n; i++)
        {
            r[i]+=r[i-1];
        }
        for (int i = 1; i < m; i++)
        {
            b[i]+=b[i-1];
        }
        // cout<<"content is as follows; ";
        // for(int i:r)cout<<i<<"  ";
        // cout<<nl;
        // for(int i:b)cout<<i<<"  ";
        // cout<<nl;
        int rmx=*max_element(r.begin(),r.end());
        int bmx=*max_element(b.begin(),b.end());

        if(rmx<=0 && bmx<=0){
            cout<<0<<nl;
        }
        if(rmx>0&&bmx>0)    cout<<rmx+bmx<<nl;
        else{
            if(rmx>0)   cout<<rmx<<nl;
            if(bmx>0)   cout<<bmx<<nl;
        }
        
    }
    



    return 0;
}