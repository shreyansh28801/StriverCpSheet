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
    int t;
    cin>>t;
    while (t--)
    {
        ll x,y,a,b;
        cin>>x>>y>>a>>b;

        ll mx,mn;
        mx=max(x,y);
        mn=min(x,y);
        // cout<<mn<<"  "<<mx<<"\n";

        ll ans=0;
        ans+=((mx-mn)*a);
        ans+=mn*b;
        ll  an1=((x+y)*a);
        cout<<min(an1,ans) <<endl;
        
    }
    



    return 0;
}