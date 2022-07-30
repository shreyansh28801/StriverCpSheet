#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<ll> v(N_local);
    */
    int t1;
    cin >> t1;
    while (t1--)
    {
        int n;
        cin >> n;
        string s, t; //s,t represent source and destination respectively
        cin >> s >> t;

        // cout<<s<<endl;

        unordered_map<char, int> ump;

        bool f1 = 0;
        for (int i = 0; i < n;)
        {
            if (s[i] == t[i])
            {
                ump[s[i]]++;
            }
            else
            {
                if (ump['0'] != ump['1'])
                {
                    f1 = 1;
                    // cout << t1 << "  NO1\n";
                    break;
                }
                int f = i;
                int l;

                // cout<<i<<"  " <<ump['0']<<"  "<<ump['1']<<"  " <<endl;
                while (s[i] != t[i] && i < n)
                {
                    // cout<<s[i]<<"  "<<t[i]<<endl;
                    ump[s[i]]++;
                    i++;
                }
                l = i - 1;
                // cout<<i<<"   " <<f<<" f and l "<<l<<"  "<<ump['0']<<"  "<<ump['1']<<"  " <<endl;
                if (ump['0'] != ump['1'])
                {
                    f1 = 1;
                    // cout << t1 << "  NO1\n";
                    break;
                }

                continue;
            }
            i++;
        }
        // cout<<"f1 is "<<f1<<"  bhjgjhghjgjh " <<ump['0']<<"  "<<ump['1'] <<endl;
        if (1 == f1)
        {
            cout << "NO\n";
        }
        else
        {
            // if(ump['0']!=ump['1'])  cout<<"   NO\n";
            cout << "YES\n";
        }
    }

    return 0;
}