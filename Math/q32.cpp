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
    ll n,m,a;
    cin>>n>>m>>a;
    ll ans=0,temp;
    ans+=(n/a);
    // cout<<ans<<" a"<<endl;
    if(n%a>0)   ans++;
    // cout<<ans<<" b"<<endl;
    temp=ans;
    if(((m/a)==0))  ans*=1;
    else if((m/a)>1)     ans*=(m/a);
    // cout<<ans<<" c"<<endl;
    if(m%a>0 && (m/a)!=0)   ans+=temp;
    cout<<ans<<endl;;





    return 0;
}