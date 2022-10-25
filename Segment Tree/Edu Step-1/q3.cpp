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
    int n, m;
    cin >> n >> m;
    vector<ll> v(n);
    cin >> v;
   
    //preprocesing
    while (__builtin_popcount(n) != 1)
    {
        n++;
        v.pub(INT_MAX);
    }
    //building
    vector<pair<ll, ll>> segTree(2 * n);
    for (int i = n; i < 2 * n; i++)
    {
        segTree[i] = {v[i-n], 1};
    }

    for (ll i = n - 1; i >= 1; i--)
    {
        if (segTree[2 * i].first == segTree[(2 * i) + 1].first)
        {
            segTree[i] = {segTree[2 * i].first, (segTree[2 * i].second + segTree[(2 * i) + 1].second)};
        }
        else
        {
            if (segTree[2 * i].first < segTree[(2 * i) + 1].first)
                segTree[i] = segTree[2 * i];
            else
                segTree[i] = segTree[(2 * i) + 1];
        }
    }

    // for(auto i:segTree){
    //     cout<<i.first<<" "<<i.second<<nl;
    // }
    // cout<<"completed"<<nl;

    //function

    function<void(ll, ll)> update = [&](ll pos, ll val)
    {
        segTree[n + pos] = {val, 1};

        for (int i = (n + pos) / 2; i >= 1; i /= 2)
        {
            if (segTree[2 * i].first == segTree[(2 * i) + 1].first)
            {
                segTree[i] = {segTree[2 * i].first, (segTree[2 * i].second + segTree[(2 * i) + 1].second)};
            }
            else
            {
                if (segTree[2 * i].first < segTree[(2 * i) + 1].first)
                    segTree[i] = segTree[2 * i];
                else
                    segTree[i] = segTree[(2 * i) + 1];
            }
        }
    };

    function<pair<ll,ll>(ll, ll, ll, ll, ll)> query = [&](ll node, ll lx, ll rx, ll l, ll r) {

        if(r<lx || l>rx)   {
            pair<ll,ll> ans={(ll)INT_MAX,0ll};
            return ans;
        }
        if(lx>=l&&rx<=r)    return segTree[node];

        ll mid=(lx+rx)/2;

        pair<ll,ll> p1=query(2*node,lx,mid,l,r);
        pair<ll,ll> p2=query((2*node)+1,mid+1,rx,l,r);

        if(p1.first==p2.first) {
            pair<ll,ll> p3={p1.first,p1.second+p2.second};
            return p3;
        }

        if(p1.first<p2.first){
            return p1;
        }
        else return p2;
    };

    //query answering

    while (m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(1==a){
            update(b,c);
        }
        else{
            pair<ll,ll> p1=query(1,0,n-1,b,c-1);
            cout<<p1.first<<" "<<p1.second<<nl;
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