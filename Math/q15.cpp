#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long int li;
typedef long double ld;
#define lb lower_bound 
#define ub upper_bound 
#define pub push_back
#define pob pop_back
typedef long double ld;

/*

const int N = 1e7+10 ;
vector<int> A(N) ;


*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<int> v(N_local);
    */ 
    int k,r;
    cin>>k>>r;
    ll ans=0,k1;
    k1=k;
    int u=15;
    while(u--)
    {
        // cout<<k<<"  "<<ans<<"  "<<u<<endl;
        if ((k%10)==0 || (k%10)==r){
            ans++;
            cout<<ans<<endl;
            break;
        }
        ans++;
        k=k1*(ans+1);
    }
    
    return 0;
}