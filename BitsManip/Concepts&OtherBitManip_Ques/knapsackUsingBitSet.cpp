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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<ll> v(N_local);
    */ 
    int n, W;
	cin >> n >> W;
    bitset<11> can;
	can[0] = true;
	for(int id = 0; id < n; id++) {
		int x;
		cin >> x;
		can = can | (can << x); // or just: can |= (can << x);
        cout<<can<<endl;
	}
	puts(can[W] ? "YES" : "NO");



    return 0;
}