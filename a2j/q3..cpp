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
bool solve(int n){
    vector<int> v;
    while (n>0)
    {
        v.pub(n%10);
        n/=10;
    }
    bool ans=true;
    for (int i = 0; i < 4; i++)
    {
        for (int j = i+1; j < 4; j++)
        {
            if(v[i]==v[j])  {
                ans=false;
                break;
            }
        }
        if(!ans)    break;
        
    }
    return ans;
    
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<int> v(N_local);
    */ 
    int n;
    cin>>n;
    for (int i = n+1;i<9013; i++)
    {
        // cout<<i<<endl;
        if(solve(i))    {
            cout<<i;
            break;
        }
    }
    



    return 0;
}