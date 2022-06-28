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
    int lh = INT_MIN, li = 0;
    int rh = INT_MAX, ri = 0;
    int h;
    for (int i = 0; i < n; i++)
    {
        cin >> h;
        if (h > lh)
            lh = h, li = i;
        if (h <= rh)
            rh = h, ri = i;
    }
    int res = li + n - 1 - ri;
    // lh    rh
    // rh    lh
    if (li < ri)
        cout << res;
    else
        cout << (res - 1);

    return 0;
}