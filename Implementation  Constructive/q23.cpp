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

int sum(int n){
    return (n*(n+1))/2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<int> v(N_local);
    */ 
//     int n;
//     cin>>n;
//     int i=0;
//     while(true){
//         n-=sum(i+1);
//         if(n>=0) i++;
//         else break;
//     }
//    cout<<i;


    int n ;
    cin>>n;
    int s=1,e=40;
    int m;
    n*=6;
    int ans=0;
    while (e-s>=0)
    {
        m=s+(e-s)/2;
        int temp=(m*(m+1)*(m+2));
        // cout<<s<<"  "<<e<<"  "<<m<<"  "<<ans<<"  "<<temp <<endl;
        if(temp>n)  e=m-1;
        else if(temp<n) s=m+1;
        else {
            ans=m;
            break;
        }
        if(e==s)   {
            // cout<<"\n yjfyuf"<<e<<"  "<<s<<  " \n";
            break;
        } 
        
    }
    // cout<<e*(e+1)*(e+2)<<"  "<<n<<endl;
    if(ans!=0)
       cout<<ans<<endl;
    else    {
        if(e*(e+1)*(e+2)>n)    cout<<e-1<<endl;
        else  cout<<e<<endl;
     
        
    }
    


    return 0;
}