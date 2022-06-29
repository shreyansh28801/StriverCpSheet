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
    vector<int> v(7);
    for (int i = 0; i < 7; i++)
        cin >> v[i];
    // full weeks
    int i = 0;
    while (n > 0)
    {
        n -= v[i];
        if (n <= 0)
            break;
        i++;
        i = i % 7;
    }
    cout << i + 1;

    return 0;
}