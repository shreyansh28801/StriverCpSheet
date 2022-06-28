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
     int k,n,w;
    cin>>k>>n>>w;
    int total_cost=0;
    for(int i=1;i<=w;i++)
    total_cost+=(i*k);
   
    int res=total_cost-n;
    if(res<0) cout<<"0";
    else cout<<res;



    return 0;
}