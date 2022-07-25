/**********
 * Ques Link -> https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-interview-prep/text-processing/string-polynomial-hashing-official/ojquestion
 * 
 * 
 * Description => Given a string S, print the hash code of that string using Polynomial Hashing.
Note: Use prime number = 31 and print the answer mod 1000000007.

*******/

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

int M = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<int> v(N_local);
    */
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll p = 31;
        ll pow = 31;
        ll ans = (s[0] - 'a' + 1);
        for (int i = 1; i < s.size(); i++)
        {
            ans += ((s[i] - 'a' + 1)*1ll*pow)%M;
            pow=(pow*1ll*p)%M;
        }
        cout<<ans<<endl;
    }

    return 0;
}