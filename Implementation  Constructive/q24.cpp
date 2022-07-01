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
      int t;
    cin>>t;
    string n;
    while(t--){
        cin>>n;
        int m=n[0]-'0';
        // cout<<m<<" hu\n";
        unordered_map<int ,int> um;
        um[1]=1;
        um[2]=3;
        um[3]=6;
        um[4]=10;
        int ans=10*(m-1);
        ans+=um[n.size()];
        cout<<ans<<endl;
    }



    return 0;
}