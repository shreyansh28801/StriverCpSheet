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



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<int> v(N_local);
    */ 
    ll n,m,k;
    cin>>n>>m>>k;
    int m1=0;
    int m2=0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        if(m1<x)    {
            m2=m1;
            m1=x;
        }
        else if(x>m2)   m2=x;
    }

    ll ans=m/(k+1);

  
    ans*=((k*m1)+m2);
   
    int w=m%(k+1);

    ans+=w*1ll*m1;
    cout<<ans<<endl;    


    return 0;
}