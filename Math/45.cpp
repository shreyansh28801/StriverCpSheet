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
    ll t,a,b,c,x,y,z;
   cin>>t;
   while(t--){
     cin>>a>>b>>c;
     z=pow(10,c-1);
     x=z,y=z;
     while(to_string(x).size()<a) x=2*x;
      while(to_string(y).size()<b) y=3*y;
      cout<<x<<" "<<y<<endl;
     
   }



    return 0;
}