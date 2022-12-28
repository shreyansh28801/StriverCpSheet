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

Problem Link  =>  https://www.codechef.com/problems/REVERSE
*/


void solve(){
    ll n,m;
    cin>>n>>m;

    vector<pair<ll,ll>> adj[n+1];

    for (ll i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back({v,0});
        adj[v].push_back({u,1});
    }

    vector<ll> cost(n+1,INT_MAX);

    //considering 1 as source and as destination and find shortest path form 1 to n.

    deque<ll> dq;
    dq.push_back(1);

    cost[1]=0;//starting node


    while (!dq.empty())
    {
        ll u=dq.front();
        dq.pop_front();

        for(auto j:adj[u]){
            ll v=j.first;
            ll wt=j.second;//denotes the weight of edge b/w u->v
            if((cost[u]+wt)<cost[v]){
                cost[v]=cost[u]+wt;
                //since we have only 2 type of weight(0/1) assigned in edges .hence for weight 0 push into front of queue for optimizing  
                if(wt==0){
                    dq.push_front(v);
                }
                else dq.push_back(v);

            }
        }

    }

    if(cost[n]==INT_MAX)cout<< -1<<nl;
    else cout<< cost[n]<<nl;
    
    

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
    t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}