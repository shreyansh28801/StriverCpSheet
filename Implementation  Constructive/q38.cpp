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
     int n,t;
    cin>>n>>t;
    
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    
    int pos=1,nxt;
    
    while(pos<t){
        nxt=pos+v[pos-1];
        pos=nxt;
    }
    
     if(pos==t) cout<<"YES";
     else cout<<"NO";



    return 0;
}