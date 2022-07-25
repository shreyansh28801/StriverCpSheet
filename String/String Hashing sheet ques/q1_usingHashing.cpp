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

    string s, s1;
    int k;
    cin >> s >> s1;
    cin >> k;
    unordered_set<char> uc_good;
    unordered_set<string> us;
    for (int i = 0; i < 26; i++)
    {
        if (s1[i] == '1')
            uc_good.insert('a' + i);
    }
    ll ans = 0;
    set<pair<ll, ll>> sp;
    for (int i = 0; i < s.size(); i++)
    {
        int badCount = 0;
        ll hash1 = 0, hash2 = 0;
        ll p1 = 31, p2 = 29;
        ll pow1 = 1, pow2 = 2;

        for (int j = i; j < s.size(); j++)
        {
            if (uc_good.find(s[j]) == uc_good.end())
                badCount++;
            if (badCount > k)
            {
                break;
            }
            else
            {
                hash1 += ((s[j] - 'a' + 1) * pow1) % M;
                hash2 += ((s[j] - 'a' + 1) * pow2) % M;
                sp.insert({hash1, hash2});
                pow1 = (pow1 * p1) % M;
                pow2 = (pow2 * p2) % M;
            }
        }
    }
    cout << sp.size() << endl;

    return 0;
}