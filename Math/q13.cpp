#include <bits/stdc++.h>
using namespace std;
#define ll  long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
        ll x,y,n;
        cin>>x>>y>>n;
        ll ans = 0;
        ans = n - n % x + y;
        if(ans <= n){
            cout<<ans<<endl;
        }
        else{
            cout<<(n - n % x - (x - y))<<endl;
        }
    }
    return 0;
}