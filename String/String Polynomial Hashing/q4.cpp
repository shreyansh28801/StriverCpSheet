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

const int N = 1e7 + 10;
vector<int> PrefixHash(N);
vector<int> dp_baseOfStringPow(N);

ll binaryExpo(int a, int b)
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

void RabinKarp(string &s)
{
    dp_baseOfStringPow[0] = 1;
    PrefixHash[0] = (s[0] - 'a' + 1);
    ll p = 31;
    for (int i = 1; i < s.size(); i++)
    {
        dp_baseOfStringPow[i] = (dp_baseOfStringPow[i - 1] * 1ll * p) % M;
        PrefixHash[i] = (PrefixHash[i - 1] + ((s[i] - 'a' + 1) * 1ll * dp_baseOfStringPow[i]) % M) % M;
    }
}

ll hashQuery(int l, int r)
{
    ll ans = PrefixHash[r];
    if (l > 0)
        ans = (ans - PrefixHash[l - 1] + M) % M;
    ll denominator = dp_baseOfStringPow[l];
    ll MMI = binaryExpo(denominator, M - 2);
    ans = (ans * 1ll * MMI) % M;
    return ans;
}

bool predicateFunc(string &s, int windowSize, ll &ans)
{
    set<ll> s1;

    for (int i = 0; i <= s.size() - windowSize; i++)
    {
        ll hashValueOfCurrentWIndow = hashQuery(i, i + windowSize - 1);
        if (s1.find(hashValueOfCurrentWIndow) != s1.end())
        {
            ans = i;
            return true;
        }
        s1.insert(hashValueOfCurrentWIndow);
    }
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
    string str;
    cin >> str;
    bool flag = 0;
    RabinKarp(str);

    ll s = 1, e = str.size() - 1;
    ll m;
    ll ans;
    while (e - s > 1)
    {
        m = (s + (e - s) / 2);
        // cout << "m and bool up " << m << "  " << predicateFunc(str, m, ans) << "  " << s << "  " << e<<"  " <<ans<< endl;
        if (predicateFunc(str, m, ans))
            s = m;
        else
            e = m - 1;
        // cout << "m and bool dn " << m << "  " << predicateFunc(str, m, ans) << "  " << s << "  " << e << endl;
    }
    if (predicateFunc(str, e, ans))
    {
        // cout << "Final " << e << "  " << ans << endl;
        while (e--)
        {
            cout << str[ans];
            ans++;
        }
    }
    else if (predicateFunc(str, e-1, ans))
    {
        // cout << "Final " << e -1<< "  " << ans << endl;
        e--;
        while (e--)
        {
            cout << str[ans];
            ans++;
        }
    }
    cout << "";

    return 0;
}
