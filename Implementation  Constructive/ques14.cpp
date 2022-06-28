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
    unordered_map<string,int> um;
    um["Icosahedron"]=20;
    um["Dodecahedron"]=12;
    um["Tetrahedron"]=8;
    um["Cube"]=6;   
    int n;
    cin>>n;
    ll ans=0;
    while (n--)
    {
        string s;
        cin>>s;
        ans+=um[s];
    }
    cout<<ans<<endl;

    return 0;
}