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
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int res = 0;
        //last row
        for (int i = 0; i < m; i++)
        {
            if (v[n - 1][i] == 'D')
                res++;
        }
        // last col
        for (int i = 0; i < n; i++)
        {
            if (v[i][m - 1] == 'R')
                res++;
        }
        cout << res << endl;
    }

    return 0;
}