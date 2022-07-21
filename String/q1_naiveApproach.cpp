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

//this solution is brute force(naive solution ) to the 1st problem of string hashing .This solution shows tle on being submitted.

string s, s1;
int k;
int fu(int i, int j, unordered_set<char> &uc)
{
    // unordered_set<char> uc1;
    int s1=0;
    for (int k = i; k < j + 1; k++)
    {
        if (uc.find(s[k]) == uc.end()){
            // uc1.insert(s[k]);

            s1++;
        }
    }
    if (s1 <= k)
        return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<int> v(N_local);
    */
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
    // for(auto i:uc_good) cout<<i<<endl;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            string s7(s.begin() + i, s.begin() + j + 1);
            if (us.find(s7) == us.end())
            {

                // cout << i << "  " << j << "  " << s7 << "  " << fu(i, j, uc_good) << endl;
                ans += fu(i, j, uc_good);
            }
            us.insert(s7);
        }
    }
    cout << ans;

    return 0;
}