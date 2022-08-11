#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long int li;
#define int long long int
typedef long double ld;
#define lb lower_bound 
#define ub upper_bound 
#define pub push_back
#define pob pop_back
typedef long double ld;

int M=1e9+7;

/*

const int N = 1e6+10 ;
vector<ll> A(N) ;


*/

bool isLower(char ch){
    int t=ch-'a';
    if(t>=0&&t<=25)  return true;
    else return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<ll> v(N_local);
    */ 
    string s;
    cin>>s;
    if(isLower(s[0])) {
        //convert it to upper
        s[0]=(s[0]-'a')+'A';
    }
    for (int i = 1; i < s.size(); i++)
    {
        if(!isLower(s[i]))   s[i]=(s[i]-'A')+'a';
    }
    cout<<s;
    



    return 0;
}