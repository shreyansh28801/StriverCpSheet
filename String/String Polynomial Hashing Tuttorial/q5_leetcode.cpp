/**
problem link => https://leetcode.com/problems/repeated-dna-sequences/
Note => this problem can be solved through brute force  under given constrinsts but still we will try to solve it through rolling hash bcz if we have to find pattern of size greater than m
whrer 10<=m<=10^5  . Now here i am assuming m is variable and it will be given as input.                      
**/

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

class Solution
{
public:
    ll binaryExponentiation(int a, int b)
    {
        ll ans = 1;

        while (b > 0)
        {
            if (b & 1 == 1)
                ans = (ans * 1ll * a) % M;
            a = (a * 1ll * a) % M;
            b >>= 1;
        }
        return ans;
    }
    vector<string> findRepeatedDnaSequences(string s)
    {

        const int N = 1e5 + 10;
        vector<int> PrefixHashValue(N);
        vector<int> dp_PowOfBaseOfString(N);

        // Rabin Karp Rolling Hash
        dp_PowOfBaseOfString[0] = 1;
        int base = 5; //as given in ques  string can only have 4 chars
        PrefixHashValue[0] = (s[0] - 'a' + 1) % M;
        for (int i = 1; i < s.size(); i++)
        {
            dp_PowOfBaseOfString[i] = (dp_PowOfBaseOfString[i - 1] * base) % M;
            PrefixHashValue[i] = (PrefixHashValue[i - 1] + ((s[i] - 'a' + 1) * dp_PowOfBaseOfString[i]) % M) % M;
        }

        set<int> s1;
        unordered_set<string> s2;
        vector<string> vv1;
        if (s.size() < 10)
            return vv1;

        for (int i = 0; i < s.size() - 9; i++)
        {
             string s11=s.substr(i,10);

            //hash value of substring of s[i...i+9]
            int l=i;
            int r=i+9;
            ll ans = PrefixHashValue[r];
            if (l > 0)
                ans = (ans - PrefixHashValue[l - 1] + M) % M;
            ll denominator = dp_PowOfBaseOfString[l];
            ll MMI = binaryExponentiation(denominator, M - 2); //using fermats liitle Theorm
            ans = (ans * MMI) % M;



            if (s1.find(ans)!=s1.end())
                s2.insert(s11);
            // else v.push_back(s1);
            s1.insert(ans);
        }
        vector<string> v(s2.begin(), s2.end());
        return v;
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