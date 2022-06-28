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
    vector<int>v(26,0);
    for(auto c:s) v[c-'a']++;
    int ct=0;
    for(auto c:v) if(c!=0) ct++;
    if(ct%2){ //odd
        cout<<"IGNORE HIM!";
    }else{
        cout<<"CHAT WITH HER!";
    }



    return 0;
}