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
    vector<vector<int>>  v(5,vector<int> (5));
    vector<vector<int>> v1(5,vector<int> (5,1));
    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            cin>>v[i][j];
        }
        
    }
    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            if(v[i][j]>0&&v[i][j]%2==1){
                v1[i][j]=1-v1[i][j];
                v1[i-1][j]=1-v1[i-1][j];
                v1[i+1][j]=1-v1[i+1][j];
                v1[i][j-1]=1-v1[i][j-1];
                v1[i][j+1]=1-v1[i][j+1];
            }
        }
        
        
    }
    
    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            cout<<v1[i][j];
        }
        cout<<"\n";
        
        
    }
    



    return 0;
}