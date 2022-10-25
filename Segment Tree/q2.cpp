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
    ll n;
    cin >> n;
    vector<ll> v(n);
    cin >> v;
    ll m;
    cin >> m;
    //preprocessing
    while (__builtin_popcount(n) != 1)
    {
        n++;
        v.pub(0);
    }
    //building seg tree

    vector<ll> segTree(n * 2);
    for (int i = n; i < 2 * n; i++)
    {
        segTree[i] = v[i - n];
    }
    for (int i = n - 1; i > 0; i--)
    {
        segTree[i] = __gcd(segTree[2 * i], segTree[(2 * i) + 1]);
    }
    // cout<<"segtree is  "<<segTree<<nl;
    //update function 

    function<void(ll,ll)> update= [&](ll pos,ll val){
        segTree[pos-1+n]=val;
        for (int i = (pos+n-1)/2; i > 0; i/=2)
        {
            segTree[i]=__gcd(segTree[2*i],segTree[(2*i)+1]);
        }
        
    };

    function<ll(ll,ll,ll,ll,ll)> query = [&](ll node,ll lx,ll rx,ll l,ll r){
        if(rx<l || lx>r)    return 0ll;
        if(lx>=l&&rx<=r)    return segTree[node];

        ll mid=(lx+rx)/2;
        ll a=query(node*2,lx,mid,l,r);
        ll b=query(node*2,mid+1,rx,l,r);
        return __gcd(a,b);
    };

    //answering the queries

    while (m--)
    {
        int a;
        cin>>a;
        if(1==a){
            ll b,c,d;
            cin>>b>>c>>d;
            cout<<"  gcd of l..r is  "<<query(1,0,n-1,b-1,c-1)<<nl;
        
        }
        else{
            ll b,c;
            cin>>b>>c;
            update(b-1,c);
        }
    }
    


}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<ll> v(N_local);
    */
    solve();

    return 0;
}