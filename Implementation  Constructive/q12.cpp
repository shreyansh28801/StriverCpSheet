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
    string n;
    cin >> n;
    int ct = 0;
    for (auto &c : n)
        if (c == '4' || c == '7')
            ct++;
    if (ct == 4 || ct == 7)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}