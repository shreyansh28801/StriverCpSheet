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
ll f(ll num)
{
    ll res1 = -1, res2 = 10;
    while (num > 0)
    {
        ll d = num % 10;
        res1 = max(res1, d);
        res2 = min(res2, d);
        num /= 10;
    }
    return res1 * res2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<int> v(N_local);
    */

    
    ll t, a, k;
    cin >> t;
    while (t--)
    {
        cin >> a >> k;
        while (--k)
        {
            ll nxt = a + f(a);
            if (a == nxt)
                break;
            a = nxt;
        }
        cout << a << endl;
    }

    return 0;
}