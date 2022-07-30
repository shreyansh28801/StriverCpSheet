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
        int n;
        vector<int> v_ip(4, 0);
        cin >> n;
        for (int i = 0; i < 4; i++)
        {
            cin >> v_ip[i];
        }

        for (int i = 0; i < (1 << 4); i++)
        {

            for (int j = 0; j < 4; j++)
            {
                if ((i & (1ll << j)) == 1)
                {
                    // v[j]--;
                    // v[3 - j]--;
                    // v[3 + j]--;
                    v_ip[j]--;
                    v_ip[3 - j]--;
                    v_ip[1 + j]--;
                }
            }
            bool f1 = 1;
            for (int i = 0; i < 4; i++)
            {
                if (v_ip[i] < 0)
                    f1 = false;
            }
            if (f1)
            {
                cout << "YES\n";
                break;
            }

            else
                continue;
        }
    }

    return 0;
}
