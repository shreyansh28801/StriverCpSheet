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
    while (t--)
    {
        ll n,k;
        cin>>n>>k;
       
        if(n>=k){
            if(n%k==0)  cout<<"1\n";
            else    cout<<"2\n";
        }
        else{
        //    cout<<(ll) ceil((float)k/n)<<"\n";
        if(k%n==0)      cout<<(k/n)<<endl;
        else    cout<<(k/n)+1<<endl;
        }
    }
    



    return 0;
}