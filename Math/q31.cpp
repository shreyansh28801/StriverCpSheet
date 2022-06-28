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
    int n;
    cin >> n;
    ll x1, y1, z1;
    x1=y1=z1=0;
    while (n--)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        x1 += x;
        y1 += y;
        z1 += z;
    }
    
    // cout<<x1<<y1<<z1; 
    if (x1 == 0 && y1 == 0 && z1 == 0)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}