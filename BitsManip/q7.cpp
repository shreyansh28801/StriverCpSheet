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
    int n, m;
    cin >> n >> m;
    bitset<1024> bitmask[n];
    map<int, set<pair<int, int>>> mp; //storing index of elemnts
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            bitmask[i][x] = 1;
            // v[x]=j;
            //mp[x].insert({j, i});
        }
        // cout<<bitmask[i] <<endl;
    }

    bitset<1024> ans;
    for (int i = 0; i < n; i++)
    {
        ans ^= bitmask[i];
        // cout<<ans<<endl;
    }
    // cout<<endl;
    // for (auto &i : mp)
    // {
    //     cout << i.first << "      ";
    //     for (auto &j : i.second)
    //         cout << "{" << j.first << ", "<< j.second<< " }, ";
    // }

    // cout<<ans<<"\n";
    vector<int> ret;
    if (ans.count() == 1 && ans[0] == 1)
        cout << "NIE\n";
    else if (ans.count() > 0)
    {
        cout << "TAK\n";
        for (int i = 0; i < 1024; i++)
        {
            if (ans[i] != 0)
            {
                int te = mp[i].size();
                if (te % 2 == 0 && te != 0)
                    te--;
                for (auto i : mp[i]){
                    if(0==te) break;
                    ret.pub(i.first);
                        te--;
                }
            }
        }
        for(int i:ret) cout<<i<<" ";
        cout<<endl;
    }
    else
        cout << "NIE\n";

    return 0;
}