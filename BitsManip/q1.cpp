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
    ll n,k;
    cin>>n>>k;
    if(1==k){
        cout<<n;
        return 0;
    }
    ll n1=n;

    int msb=0;
    while(n1!=0){
        msb++;
        n1>>=1;
    }

    ll ans=((1<<(msb))-1);
    cout<<ans;





    return 0;
}