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
    int n, m;
    cin >> n >> m;
    int ans = -1;
    if (n == m)
    {
        cout << "0";
        return 0;
    }
    else if (m % n == 0)
    {
        ans = 0;
        int d = m / n;
        while (d % 2 == 0)
            d /= 2, ans++;

        while (d % 3 == 0)
            d /= 3, ans++;
        if (d != 1)
            ans = -1;
    }
    cout << ans;

    return 0;
}