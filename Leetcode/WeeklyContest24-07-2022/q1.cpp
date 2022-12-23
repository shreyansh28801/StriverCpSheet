#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long int li;
#define int long long int
typedef long double ld;
#define lb lower_bound
#define ub upper_bound
#define pub push_back
#define pob pop_back
typedef long double ld;

int M = 1e9 + 7;

/*

const int N = 1e7+10 ;
vector<ll> A(N) ;


*/

class Solution
{
public:
    char repeatedCharacter(string str)
    {
        set<char> s;
        for (int i = 0; i < str.size(); i++)
        {
            if (s.find(str[i]) == s.end())
                s.insert(str[i]);
            else
                return str[i];
        }
        return 'a';
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<ll> v(N_local);
    */

    return 0;
}