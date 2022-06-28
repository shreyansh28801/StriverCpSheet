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
      int n;
    cin>>n;
    string s;
    cin>>s;
    string ans="";
    int j=1;
    int i=0;
    while(i<n){
        ans.push_back(s[i]);
        i+=(j++);
    }
    cout<<ans;



    return 0;
}