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

bool checkXMatrix(vector<vector<int>> &grid)
{
    bool ans=true;
    int n=grid.size();
  
    for (int i = 1; i <= n-1 ; i++)
    {
        for (int j = 1; j < n-1; j++)
        {
             if(i==j || (i+j)==n-1){
                if(grid[i][j]==0)   return false;
             }
             else if (grid[i][j] !=0)   return false;
        }
        
    }
    return true;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<int> v(N_local);
    */

    return 0;
}