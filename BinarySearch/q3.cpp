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

int M = 1e9 + 7;

/*

const int N = 1e6+10 ;
vector<ll> A(N) ;


*/

int n, k;
bool isPredicate(int s,int e)
{
    int sumUptos=(s*(s+1))/2;   

    sumUptos--;
    
    int sumUptoe=(e*(e+1))/2;   

    sumUptoe--;

    sumUptoe-=sumUptos;

    if(sumUptoe>k)  true;

}
    int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<ll> v(N_local);
    */
    cin >> n >> k;

    int s = 0;
    int e = k;
    int m;
    while ((e - s) > 0)
    {
        m=(s+e)/2;
        if(isPredicate(s,e)) e=m;
        else s=m+1;
    }

    return 0;
}