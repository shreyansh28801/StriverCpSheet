
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

    ll n, k, x;
    cin >> n >> k;
    vector<int> v(k + 1);
    ll cap = ceil(1.0 * n / 2);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v[x]++;
    }
    ll odd = 0, even = 0;
    for (int i = 0; i <= k; i++)
    {
        if (v[i] % 2)
            even += (v[i] - 1), odd++;
        else
            even += v[i];
    }
    ll res = 0;
    res += 2 * min(even / 2, cap);
    cap -= min(even / 2, cap);
    res += cap;
    cout << res;

    return 0;
}
