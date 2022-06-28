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
    string s;
    cin >> s;
    ll ans = 0;
    int i = 0;
    int n = s.size();
    // cout << " n is  " << n << endl;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            // cout << n - i - 1 << "  " << ans << endl;
            ans += (n - i - 1) / 2;
            ans++;
            break;
        }
    }
    int ct=0;

    for(char c:s)   if(c=='1')  ct++;
    // cout<<i<<"  "<<ct<<"  "<<ans<<endl;
    if((n-1-i)%2==0 && ct==1)    ans--;
    cout << ans << endl;

    return 0;
}