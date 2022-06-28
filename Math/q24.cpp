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

    ll x, y, z;
    cin >> x >> y >> z;
    ll r1 = y % z;
    ll r2 = x % z;
    ll ans1,ans2;
    // cout<<r1<<"  "<<r2<<endl;
    if (r1 != 0 && r2 != 0)
    {
        // cout<<"kujgju";
        if(r1+r2>=z) {
            ans1=z-max(r1,r2);
        }
        else    ans1=0;
        
        ans2= (x+y)/z ;
    }
    else
    {
        ans1 = min(r1, r2);
        y -= ans1;
        x += ans1;
        ans2= (y / z) + (x / z) ;
    }

    cout << ans2 << " " <<ans1 << endl;

    return 0;
}
