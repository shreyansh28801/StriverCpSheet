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

    function<void(ll, ll)> update = [&](ll pos, ll val)
    {
        segTree[pos  + n] = val;
        for (int i = (pos + n ) / 2; i > 0; i /= 2)
        {
            segTree[i] = __gcd(segTree[2 * i], segTree[(2 * i) + 1]);
        }
    };

    ll minus1Ct=0;
    ll nodeNumber=-1;

    function<ll(ll, ll, ll, ll, ll, ll)> query = [&](ll node, ll lx, ll rx, ll l, ll r, ll required_gcd)
    {
        if (rx < l || lx > r)
        {
            // cout<<0<<nl;
            return 0ll;
        }
        if (lx >= l && rx <= r)
        {
            if (segTree[node] % required_gcd == 0)
            {
                // cout<<segTree[node] <<nl;
                return segTree[node];
            }
            else
            {
                //  cout << node <<"  "<< lx << "  " << rx << "  " << l << "  " << r << "  returning  "<<nl;
                // cout<< -1<<nl;
                minus1Ct++;
                nodeNumber=node;
                return -1ll;
            }
        }

        ll mid = (lx + rx) / 2;
        ll a = query(node * 2, lx, mid, l, r, required_gcd);
        // if(a==-1)   return -1;
        ll b = query((node * 2)+1, mid + 1, rx, l, r, required_gcd);
        if (b == -1 && a == -1)
        {
        
            // cout<< -1<<nl;
            return -1ll;
        }
        else
        {
            // cout<< required_gcd<<nl;
            return required_gcd;
        }
    };

    //answering the queries

    while (m--)
    {
        int a;
        cin >> a;
        if (1 == a)
        {
            ll b, c, d;
            cin >> b >> c >> d;
            minus1Ct=0;
            ll temp=query(1,0,n-1,b-1,c-1,d);
            // cout<<minus1Ct<<nl;
            // if(minus1Ct>=2) {
            //     cout<<"NO"<<nl;
            //     continue;
            // }
            // else if(minus1Ct==0)  cout<<"YES\n";
            // else if (d == query(1, 0, n - 1, b - 1, c - 1, d))
            //     cout << "YES\n";
            // else cout<<"NO\n";
            if(minus1Ct>=2) cout<<"NO\n";
            else {
                // cout<<minus1Ct<<"  YES\n";
                if(minus1Ct==0)cout<<"YES\n";
                else {
                    ll ptr=nodeNumber;
                    bool flag=1;
                    while (ptr<n)
                    {
                        if(segTree[ptr*2]%d!=0 && segTree[(ptr*2)+1]%d!=0)  {flag=0;cout<<"NO\n";break;}
                        else{
                            if(segTree[2*ptr]%d==0){
                                ptr=(ptr*2)+1;
                            }
                            else ptr=ptr*2;
                        }
                    }
                    if(1==flag){
                        cout<<"YES\n";

                    }
                    
                    
                }
            }
            
        }
        else
        {
            ll b, c;
            cin >> b >> c;
            update(b - 1, c);
            // cout<<"updated seg tre  "<<segTree<<nl;
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