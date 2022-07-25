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

// Ques Link =>  https://codeforces.com/problemset/problem/126/B

const int N = 1e7 + 10;
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
    vector<int> v(N_local);
    */
    string s;
    cin >> s;

    RabinKarpRollingHash(s);

    // cout<<"printing base ppower\n";
    // for (int i = 0; i < s.size(); i++)
    // {
    //     cout<<dp_PowOfBaseOfString[i]<<" ";
    // }
    // cout<<"prefix hash dp\n";
    // for (int i = 0; i < s.size(); i++)
    // {
    //     cout<<PrefixHashValue[i]<<" ";
    // }
    // cout<<endl;
    

    int ans = 0; //size of output string
    for (int i = 0; i < s.size() - 1; i++)
    {
        ll hvp = PrefixHashValue[i];                        // hash value of current prefix
        ll hvs = hashQuery(s.size() - 1 - i, s.size() - 1); // hash value of current suffix
        // hvp = (hvp * 1ll * dp_PowOfBaseOfString[s.size() - 1 - i]) % M;

        if (hvp == hvs)
        { 
            // cout<<"\n\nhello\n\n";
            int sp = 1;

            int ep = i+1;

            while (ep < s.size() - 1)
            {
                ll windowhash = hashQuery(sp, ep);
                // cout<<"\n i , windowhash  "<<i<<"   "<< hvp<<"  "<<windowhash<<endl;
                if (windowhash == (hvp ))
                {
                    ans =i+1;
                    break;
                }
                sp++, ep++;
            }
        }
    }
    if (0 == ans)
        cout << "Just a legend";
    else
    {
        for (int i = 0; i < ans; i++)
        {
            cout << s[i];
        }
    }

    return 0;
}