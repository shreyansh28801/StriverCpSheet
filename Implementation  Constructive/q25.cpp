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
    string s;
    while (t--)
    {
        cin >> s;
        int prev = -1;
        int res = 0;
        for (int i = 0; i <s.size(); i++)
        {
            if (s[i] == '1')
            {
                if (prev != -1)
                    res += (i - prev - 1);
                prev = i;
            }
        }
        cout << res << endl;
    }

    return 0;
}