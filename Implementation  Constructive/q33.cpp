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
    for (int rw = -n; rw <= n; rw++)
    {

        int spaces = 2 * abs(rw);
        for (int i = 0; i < spaces; i++)
            cout << " ";
        int max = n - abs(rw);
        for (int i = 0; i < max; i++)
            cout << i << " ";
        for (int i = max; i > 0; i--)
            cout << i << " ";

        cout << 0 << endl;
    }

    return 0;
}