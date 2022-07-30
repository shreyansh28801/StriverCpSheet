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

int M = 1e9 + 7;

/*

const int N = 1e7+10 ;
vector<ll> A(N) ;


*/

int M = 1e9 + 7;

// Ques Link =>  https://codeforces.com/problemset/problem/126/B

const int N = 1e6 + 10;
vector<int> PrefixHashValue(N);
vector<int> dp_PowOfBaseOfString(N);



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

void RabinKarpRollingHash(string &s)
{
    ll p = 31;
    dp_PowOfBaseOfString[0] = 1;
    PrefixHashValue[0] = (s[0] - 'a' + 1);
    for (int i = 1; i < s.size(); i++)
    {
        dp_PowOfBaseOfString[i] = (dp_PowOfBaseOfString[i - 1] * 1ll * p) % M;
        PrefixHashValue[i] = (PrefixHashValue[i - 1] + ((s[i] - 'a' + 1) * 1ll * dp_PowOfBaseOfString[i]) % M) % M;
    }
}

ll hashQuery(int l, int r)
{
    /*
    formualae => ((prefixHash[r]-prefixHash[l-1])/dp_PowOfBaseOfString[l])%M;
    Here we have to calculate MMI(Modular Multiplicative Inverse of Denominator)
    */
    ll ans = PrefixHashValue[r];
    if (l > 0)
        ans = (ans - PrefixHashValue[l - 1] + M) % M;
    ll denominator=dp_PowOfBaseOfString[l];
    ll MMI=binaryExponentiation(denominator,M-2);//using fermats liitle Theorm
    ans=(ans*MMI)%M;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<ll> v(N_local);
    */
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin>>str;
        int n=str.size();

        RabinKarpRollingHash(str);

        for (int  i = 0; i < n; i++)
        {
            for (int j = i+1; j < n; j++)
            {
                int a=hashQuery(0,i);
                int b=hashQuery(j,str.size()-1);

                b=(b*(binaryExponentiation(31,i+1))%M);

                //calulating hash value of reverse of (a+b) 

                
            }
            
        }
        



        
    }

    return 0;
}