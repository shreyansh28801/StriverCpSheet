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

const int N = 1e6+10 ;
vector<ll> A(N) ;


*/

class DisjointSetUnion
{
private:
    vector<int> size,parent,rank;
public:
    DisjointSetUnion(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        rank.resize(n+1,0);
        for (ll i = 0; i < n+1; i++)
        {
            parent[i]=i;
        }       

    }
    int findParent(int node){
        if(parent[node]==node)return node;
        // return findPaent(parent[node]);  //logarithnic Time Complexity of find Parent if this type of return method is apllied

        //for doing path compression simple update the parent before returning
        return parent[node]=findParent(parent[node]);
    }


    void unionBySize(int u,int v){
        int ul_p_u=findParent(u);//ultimate parent of u
        int ul_p_v=findParent(v);//ultimate parent of v

        if(ul_p_u==ul_p_v)return;//this means we don't need to connect these nodes these are already connected.

        if(size[ul_p_u]==size[ul_p_v]){
            //size of ultimate parent of u and v are same .So we have liberty to joint in any way (Suppose i am connecting ultimate parent of v with ultimate parent of u)

            size[ul_p_u]+=size[ul_p_v];//size of ultimate parent of u will be its initial size plus size of ultimate parent of v
            parent[ul_p_v]=ul_p_u;//parent of ultimate parent of v will be ultimate parent of u;
        }
        else if(size[ul_p_u]>size[ul_p_v]){
            // in this case we will connect ultimate parent of v with ultimate parent of u(going under the shelter of ultimate parent of u)
            size[ul_p_u]+=size[ul_p_v];
            parent[ul_p_v]=ul_p_u;

        }
        else{
            // in this case we will connect ultimate parent of u with ultimate parent of v(going under the shelter of ultimate parent of v)
            size[ul_p_v]+=size[ul_p_u];
            parent[ul_p_u]=ul_p_v; 
        }
    }


    void unionByRank(int u,int v){
        int ul_p_u=findParent(u);//ultimate parent of u
        int ul_p_v=findParent(v);//ultimate parent of v

        if(ul_p_u==ul_p_v)return;//this means we don't need to connect these nodes these are already connected.

        if(rank[ul_p_u]==rank[ul_p_v]){
            //rank of ultimate parent of u and v are same .So we have liberty to joint in any way (Suppose i am connecting ultimate parent of v with ultimate parent of u)

    
            parent[ul_p_v]=ul_p_u;//parent of ultimate parent of v will be ultimate parent of u;
        }
        else if(rank[ul_p_u]>rank[ul_p_v]){
         
            parent[ul_p_v]=ul_p_u;
        }
        else{
           
            parent[ul_p_v]=ul_p_u; 
            rank[ul_p_u]++;
        }
    }
};




void solve(){
    

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    DisjointSetUnion ds(7);
    //I wil prefer union by size over union by rank(bcz union by size much more intuitive)

    //Note => 1. while implementing the data structure implement using by rank or size .Don't use together.
    //Note => 2. Both union by rank and union by dize take same T.C. that is O(4a)(a is known as alpha ,very complicated to derive it and alpha close to 1. )

    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);

    //let's check that 3 and 7 belong to same set or not
    if(ds.findParent(3)==ds.findParent(7)){
        cout<<"same \n";
    }
    else cout<<"not same\n";
    ds.unionBySize(3,7);
    
    //now again let's check that 3 and 7 belong to same set or not
    if(ds.findParent(3)==ds.findParent(7)){
        cout<<"same \n";
    }
    else cout<<"not same\n";
    ds.unionBySize(3,7);

    return 0;
}