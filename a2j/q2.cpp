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
    string s;
    cin>>s;
    unordered_map<string ,int> um;
    um["."]=0;
    um["-."]=1;
    um["--"]=2;
    string ans;
    while (s.size()>0)
    {
        int a1=s.find(".");
        int a2=s.find("-.");
        int a3=s.find("--");
        // cout<<a1<<"  "<<a2<<"   "<<a3<<"   "<<s<<"  ans    "<<ans <<endl;
        if(a1==0)   {
            ans.pub('0');
            s.erase(s.begin(),s.begin()+1);
        }
        else if(0==a2){
            ans.pub('1');
            s.erase(s.begin(),s.begin()+2);

        }
        else{

            ans.pub('2');
            s.erase(s.begin(),s.begin()+2);
        }
    }
    cout<<ans<<endl;
    
    



    return 0;
}