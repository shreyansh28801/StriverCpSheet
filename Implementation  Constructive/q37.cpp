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
    int res = 0;
    if (m > n)
    {
        res = -1;
    }
    else
    {
        if (n % 2)
            res = n / 2 + 1;
        else
            res = n / 2;
        while (res % m > 0)
            res++;
    }

    cout << res;

    return 0;
}