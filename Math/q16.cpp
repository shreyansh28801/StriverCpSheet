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
    vector<ll> v(4);
    ll s = 0;
    for (int i = 0; i < 4; i++)
    {
        cin >> v[i];
        s += v[i];
    }
    s /= 3;
    auto it = find(v.begin(), v.end(), s);
    for (auto i = v.begin(); i != v.end(); i++)
    {
        if (i != it)
            cout << *it - *i<<" ";
    }

    return 0;
}