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
    // cout<<"dsahhj";
    for (int i = 1; i < n + 1; i++)
    {
        if ((i % 2) == 1)
        {
            // cout<<"1   ";
            for (int j = 1; j < m + 1; j++)
            {
                cout << "#";
            }
            cout << endl;
            continue;
        }
        else
        {
            // cout<<"2   ";
            if ((i / 2) % 2 == 1)
            {
                for (int i1 = 0; i1 < m; i1++)
                {
                    if (i1 == m - 1)
                        cout << "#";
                    else
                        cout << '.';
                }
                cout << endl;
            }
            else
            {
                for (int i1 = 0; i1 < m; i1++)
                {
                    if (i1 == 0)
                        cout << '#';
                    else
                        cout << '.';
                }
                cout << endl;
            }
        }
    }

    return 0;
}