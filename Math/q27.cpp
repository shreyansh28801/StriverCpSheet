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
     ll n,x,y;
       cin>>n;
       while(n--){
           cin>>x>>y;
          if(x>=y) cout<<y<<endl;
          else{
              ll t=y/x;
              ll res=0;
              ll extra=y%x;
              if(extra==0) res=x*t*t;
              else res=(t*t*(x-extra))+extra*(t+1)*(t+1);
              cout<<res<<endl;
          }
       }



    return 0;
}