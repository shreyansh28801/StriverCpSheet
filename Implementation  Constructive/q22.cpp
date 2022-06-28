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
    cin >> s;
    vector<string> v(5);
    for (int i = 0; i < 5; i++)
        cin >> v[i];

    unordered_map<char,bool> um;
    for(string s:v){
        um[s[1]]=true;
        um[s[0]]=true;
    }
    if(um.find(s[0])!=um.end()  ||  um.find(s[1])!=um.end())    cout<<"YES\n";
    else cout<<"NO\n";

    return 0;
}