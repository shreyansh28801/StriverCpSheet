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

const int N = 1e6+10 ;
vector<ll> A(N) ;

*/


class Solution
{
public:
    string longestPalindrome(string s)
    {

        const int N = 1e3 + 10;
        vector<int> PrefixHashValue(N);
        vector<int> dp_PowOfBaseOfString(N);

        // Rabin Karp Rolling Hash
        dp_PowOfBaseOfString[0] = 1;
        int base = 31; //as given in ques  string can only have 4 chars
        PrefixHashValue[0] = (s[0] - 'a' + 1) % M;
        for (int i = 1; i < s.size(); i++)
        {
            dp_PowOfBaseOfString[i] = (dp_PowOfBaseOfString[i - 1] * 1ll * base) % M;
            PrefixHashValue[i] = (PrefixHashValue[i - 1] + (((s[i] - 'a' + 1) * 1ll * dp_PowOfBaseOfString[i]) % M)) % M;
        }
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

   cout<<INT_MAX<<endl;

    return 0;
}