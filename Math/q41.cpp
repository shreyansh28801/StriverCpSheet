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
        int n,m,k;
        cin>>n>>m>>k;
        if (m==0 || m==1)
        {
            cout<<m<<"\n";
        }
        else if((n/k)>=m)    cout<<m<<endl;
        else    {
        //    ll ans=((m-(n/k))/(k-1));
            if((m-(n/k))<=(k-1))     cout<<(n/k)-1<<endl;
            else  {
                    // cout<<((n/k)-((m-(n/k))/(k-1)+1)) <<endl;
                    // cout<<(n/k)<<"   " <<(m-(n/k))<<"   "<<(k-1)<<" gh \n";
                    // cout<<"nn";
                    if((m-(n/k))%(k-1)==0)  cout<<(n/k)-((m-(n/k))/(k-1))<<endl;    
                    else    cout<<(n/k)-((m-(n/k))/(k-1))-1<<endl;
                    
            }  
        }
        
    }
    



    return 0;
}