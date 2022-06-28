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

  

    int t, a, b, n;
    cin >> t ;
    while (t--)
    {
        cin >> a >> b >> n;
        int ans=0;
        while (max(a, b) <= n)
        {
            ans++;
            if (a < b)
            {
                a += b;
            }
            else    b+=a;
        }
        cout <<ans<<endl;
    }

    return 0;
}