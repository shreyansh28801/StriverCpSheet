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
    int arr[3]={0,0,0};
    for(auto c:s){
        if(c=='1') arr[0]++;
        else if(c=='2') arr[1]++;
        else if(c=='3') arr[2]++;
    }
    string ans;
    for(int i=0;i<3;i++){
        while(arr[i]--){
            ans.push_back('+');
            ans.push_back(i+1+'0');
        }
    }
    ans=ans.substr(1);
    cout<<ans;



    return 0;
}