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
    ll t, a, b, c;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        ll sum = a + b + c;
        ll k = sum / 9;
        if (sum % 9 == 0 and a >= k and b >= k and c >= k)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}