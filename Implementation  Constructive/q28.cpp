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

bool vowel(char c)
{
    string s = "AEIOUYaeiouy";
    for (auto ch : s)
        if (ch == c)
            return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<int> v(N_local);
    */
    string s, res = "";
    cin >> s;
    for (auto c : s)
    {
        if (!vowel(c))
        {
            res.push_back('.');
            if (c >= 'A' && c <= 'Z')
            {
                int i = (c - 'A');
                res.push_back('a' + i);
            }
            else
                res.push_back(c);
        }
    }
    cout << res;

    return 0;
}