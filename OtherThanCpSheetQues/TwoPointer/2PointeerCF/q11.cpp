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
        int k,n,m;
        cin>>k>>n>>m;
        vector<int> v_mono;
        vector<int> v_poly;
        for (int i = 0; i < (n); i++)
        {
            int x;
            cin>>x;
            v_mono.pub(x);
        }
        for (int i = 0; i < (m); i++)
        {
            int x;
            cin>>x;
            v_poly.pub(x);
        }
        // int mx=*(max_element(v.begin(),v.end()));
        // int ct_0=count(v.begin(),v.end(),0);
        // if((ct_0+k)<mx) cout<<"-1\n";
        // else {
        //    for (int i = 0; i < (n+m); i++)
        //    {
        //         if(v[i]==0){
        //             k++;
        //             cout<<
        //         }
        //    }
           
        // }
        

        int mono_pointer=0;
        int poly_pointer=0;

        vector<int> ans;
        bool f=1;

        while (mono_pointer<n && poly_pointer<m)
        {
            if(v_mono[mono_pointer]==0 && v_poly[poly_pointer]==0){
                k+=2;
                ans.pub(0);
                ans.pub(0);
                mono_pointer++;
                poly_pointer++;
            }   
            else if(v_mono[mono_pointer]==0 || v_poly[poly_pointer]==0){
                k++;
                ans.pub(0);
                if(v_mono[mono_pointer]==0) mono_pointer++;
                else poly_pointer++;
            }
            else{
                if(v_mono[mono_pointer]<v_poly[poly_pointer])   {
                    if(v_mono[mono_pointer]>k)  {
                        cout<<"-1\n";
                        f=0;
                        break;
                    }
                    else{
                        ans.pub(v_mono[mono_pointer]);
                        mono_pointer++;
                    }
                }
                else{
                    if(v_poly[poly_pointer]>k)  {
                        cout<<"-1\n";
                        f=0;
                        break;
                    }
                    else{
                        ans.pub(v_poly[poly_pointer]);
                        poly_pointer++;
                    }

                }
            }
        }
        if(0==f)    continue;
        while (mono_pointer<n)
        {
            if(v_mono[mono_pointer]==0){
                ans.pub(0);
                k++;
                mono_pointer++;
            }
            else{
                 if(v_mono[mono_pointer]>k){
                    cout<<"-1\n";
                    f=0;
                    break;
                 }
                 else{
                    ans.pub(v_mono[mono_pointer]);
                    mono_pointer++;
                 }
            }
        }
        while (poly_pointer<m)
        {
            if(v_poly[poly_pointer]==0){
                ans.pub(0);
                k++;
                poly_pointer++;
            }
            else{
                 if(v_poly[poly_pointer]>k){
                    cout<<"-1\n";
                    f=0;
                    break;
                 }
                 else{
                    ans.pub(v_poly[poly_pointer]);
                    poly_pointer++;
                 }
            }
        }
        
        if(1==f){
            for (int i = 0; i < ans.size(); i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
            
        }
        
    }
    



    return 0;
}