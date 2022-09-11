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

https://leetcode.com/problems/string-compression/

*/

class Solution {
public:
    int compress(vector<char>& cs) {
        int n=cs.size();
        
        int s=-1;
        int e=0;
        char c=cs[e];
        int sz=0;
        while(e<n){
        
            if(cs[e]==c){
                e++;
                sz++;
            }
            else{
                cout<<c<<"  "<<sz<<endl;
                
               cs[++s]=c;
                c=cs[e];
                // cout<<c<<"  "<<sz<<endl;
                if(1==sz) {
                    sz=0;
                    continue;
                }
                string str=to_string(sz);
                sz=0;
                for(char ch:str){
                    cs[++s]=ch;
                }
                
            }
        }
        if(sz>0){
            cs[++s]=c;
            if(sz==1)   return s+1;
            string str=to_string(sz);
                
            for(char ch:str){
                cs[++s]=ch;
            }

        }
        
        return s+1;            
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<ll> v(N_local);
    */ 
    



    return 0;
}