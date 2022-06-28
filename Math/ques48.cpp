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
   if(n<=2) {cout<<"No"<<endl; return 0;}
   
   cout<<"Yes"<<endl;
   cout<<n-1;
   for(int i=1;i<=n-1;i++)
   cout<<" "<<i;
   cout<<endl;
   cout<<1<<" "<<n<<endl;

    return 0;
}