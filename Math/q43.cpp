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

    const int N_local = 1e5;
    vector<int> v(N_local);

    ll n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll ans = 0, ans1 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ll di = v[i] - v[i + 1];
        if (di >= 0)
            ans1 += (v[i] - v[i + 1]);
        else
        {
            di *= -1;
            if (di <= ans1)
                ans1 -= di;
           else{
              ans += (di-ans1);
              ans1=0;
           }
            // cout << i << "  " << di << "  "<< ans1<< endl;
        }
    }

    ans += v[0];
    cout << ans << endl;

    return 0;
}