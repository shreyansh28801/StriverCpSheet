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
   int res=0;
   string s;
   for(int i=0;i<n;i++){
       cin>>s;
       if(s=="Tetrahedron") res+=4;
       else if(s=="Cube") res+=6;
       else if(s=="Octahedron") res+=8;
       else if(s=="Dodecahedron") res+=12;
       else if (s=="Icosahedron") res+=20;
   }
   cout<<res;



    return 0;
}