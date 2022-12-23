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

vector<ll> segTree(33554432);

void solve()
{
    //pre  preocessing
    ll x = segTree.size();
    // while (__builtin_popcount(x) != 1)
    // {
    //     x++;
    //     segTree.push_back(0);
    // }
    // x = (ll)segTree.size();
    // ll x2=x;
    // cout << x << endl;
    // while (x2--)
    // {
    //     segTree.push_back(0);
    // }
    // cout<<"x is as : " <<x<<nl;
    ll n, q;
    cin >> n >> q;

    vector<ll> p(n);
    cin >> p;

    unordered_map<ll,ll,cstH> m;
    for(auto x : p){
        m[x]++;
    }

    for (int i = 0; i < n; i++)
    {
        // p[i] ==> 5
        // segTree[x+5]
        segTree[x+p[i]/100]++;
    }

    //building seg tree
    for (int i = x - 1; i >= 1; i--)
    {
        segTree[i] = segTree[(2 * i) + 1] + segTree[2 * i];
    }
    
    //============BUILT=================//

    //update seg tree
    function<void(ll, ll)> update = [&](ll k, ll x1)
    {
        // p[k-1] ==> salary of kth person
        segTree[x+p[k-1]/100]--;
        m[p[k-1]]--;
        for (ll i = (x+p[k - 1]/100) / 2; i >= 1; i /= 2)
        {
            segTree[i] = segTree[2 * i] + segTree[(2 * i) + 1];
        }
        segTree[x+x1/100]++;
        for (ll i = (x+x1/100)/ 2; i >= 1; i /= 2)
        {
            segTree[i] = segTree[2 * i] + segTree[(2 * i) + 1];
        }
        m[x1]++;
        p[k-1] = x1;
    };

    //query function
    function<ll(ll, ll, ll, ll, ll)>
        query = [&](ll node, ll lx, ll rx, ll l, ll r)
    {
        // cout<<lx<<" "<<rx<<"  " <<node<<nl;
        if (l > rx || r < lx)
            return 0ll;
        if (lx >= l && rx <= r)
            return segTree[node];

        ll mid = (lx + rx) / 2;
        ll ans1=query(2*node,lx,mid,l,r);
        ll ans2=query((2*node)+1,mid+1,rx,l,r);
        return ans1+ans2;
    };

    //addresing query
    while (q--)
    {
        char ch;
        cin>>ch;
        if(ch=='!'){
            ll k,x1;
            cin>>k>>x1;
            update(k,x1);
        }
        else{
            ll a,b;
            cin>>a>>b;
            ll b1 = a/100;
            ll b2 = b/100;
            if(b1==b2 || b1==b2-1){
                ll ans = 0;
                for(ll i=a; i<=b; i++){
                    if(m.find(i)!=m.end()){
                        ans += m[i];
                    }
                }
                cout << ans << nl; continue;
            }
            ll ans1 = 0; ll ans2 = 0; ll ans3 = 0;
            for(ll i=a; i<=(a/100+1)*100-1; i++){
                if(m.find(i) != m.end()){
                    ans1 += m[i];
                }
            }
            for(ll i=b; i>=(b/100)*100; i--){
                if(m.find(i) != m.end()){
                    ans3 += m[i];
                }
            }
            ans2 = query(1, 0, x-1, b1+1, b2-1);
            cout << ans1 + ans2 + ans3 << nl;
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
    int t;
    t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}