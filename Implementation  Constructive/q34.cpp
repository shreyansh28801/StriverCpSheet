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
    int a, b;
    cin >> a >> b;
    if (b % a == 0)
    {
        int x = b / a;

        int ct = 0;
        while (x % 2 == 0)
        {
            // cout<<x<<endl;
            x /= 2;
            ct++;
        }
        while (x % 3 == 0)
        {
            // cout<<x<<endl;
            x /= 3;
            ct++;
        }
        if (x > 1 || (0 == ct && a != b))
            cout << -1 << endl;
        else
            cout << ct << endl;
    }
    else
        cout << "-1\n";

    return 0;
}