#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long int li;
#define int long long int
typedef long double ld;
#define lb lower_bound
#define ub upper_bound
#define pub push_back
#define pob pop_back
typedef long double ld;

int M = 1e9 + 7;

const int N = 1e6 + 10;

vector<int> Z_Function(N, 0);

void zfunction(string &s)
//This is Brute force approach to build z function .its T.C. will be O(s.size|()*max_element_of_Z_Function) but in worst case it is O(N^2) where n=s.size()
{
    for (int i = 1; i < s.size(); i++)
    {
        while (s[Z_Function[i]] == s[i + Z_Function[i]])
        {
            Z_Function[i]++;
        }
    }
}

void zfunction_Optimized(string &s)
//T.C. => O(n)  where n=s.size()
{
    int l=0;
    int r=0;
    for (int i = 0; i < s.size(); i++)
    {
        if(i<=r){
            Z_Function[i]=min(r-i+1,Z_Function[i-l]);
        }
        while (s[Z_Function[i]] == s[i + Z_Function[i]])
        {
            Z_Function[i]++;
        }
        if(i+ Z_Function[i]-1>r )   {
            l=i;
            r=i+Z_Function[i]-1;

        }
    }
    

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

    cin >> s;

    return 0;
}