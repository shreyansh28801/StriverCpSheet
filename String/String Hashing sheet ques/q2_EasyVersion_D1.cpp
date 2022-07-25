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

int M = 1e9 + 7;

/*

const int N = 1e7+10 ;
vector<ll> A(N) ;


*/

bool isPalin(string &s){
    string s1=s;
    reverse(s1.begin(),s1.end());
    if(s1!=s)   return false;
    else return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<ll> v(N_local);
    */
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin>>str;
        int n=str.size();
        int s = 0;
        int e = str.size() - 1;
        while (s!=e)
        {
            if(str[s]!=str[e])  break;
            else{
                s++;
                e--;
            }
        }
        // if()
        for (int i = s; i < n; i++)
        {
            string tr(str.begin()+s,str.begin()+i+1);
            if(isPalin(tr)==false) break;
        }
        
        
    }

    return 0;
}