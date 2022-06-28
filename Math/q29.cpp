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
    ll t, w, h, k, p, first, last;
    cin >> t;
    while (t--)
    {
        cin >> w >> h;
        ll area = 0;
        for (int i = 0; i < 4; i++)
        {
            cin >> k;
            for (int j = 0; j < k; j++)
            {
                cin >> p;
                if (j == 0)
                    first = p;
                else if (j + 1 == k)
                    last = p;
            }
            ll base = last - first;
            if (i < 2)
                area = max(area, base * h);
            else
                area = max(area, base * w);
        }
        cout << area << endl;
    }

    return 0;
}