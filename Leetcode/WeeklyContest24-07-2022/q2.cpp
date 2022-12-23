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

/*

const int N = 1e7+10 ;
vector<ll> A(N) ;


*/

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        vector<vector<int>> vv1;
        int ans = 0;
        for (int i = 0; i < grid[0].size(); i++)
        {
            vector<int> temp;
            for (int j = 0; j < grid.size(); j++)
            {
                temp.push_back(grid[j][i]);
            }
            vv1.push_back(temp);
        }
       for (int i = 0; i < grid.size(); i++)
       {
           for (int j = 0; j < vv1.size(); j++)
           {
            if(vv1[j]==grid[i]) ans++;
           }
           
            
       }
       

        return ans;
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