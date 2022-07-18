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

const int M = 1e9 + 7;

/*

const int N = 1e7+10 ;
vector<int> A(N) ;


*/

ll binaryExponentiationIterativeApproach(int a, int b)
// we have to return a^b(b is exponent of a)
//  a,b,M<=10^9
//T.Com.   =>  log(b)
{
    ll ans = 1;
    while (b > 0)
    {

        if ((b & 1) > 0)
        {
            ans = (a * 1ll * ans) % M;
        }
        a = (a * 1ll * a) % M;
        b >>= 1;
    }
    return ans;
}

//is number a power of 2
bool isNumberPowerOf2(int num)
{
    // if (0==num)
    // {
    //     cout<<"\n we can' decide in case of zero \n";
    // }

    return !(num & (num - 1));
}

int fu(int a)
{
    int ans = 0;
    while (a > 0)
    {
        // cout<<a<<"  ";
        ans++;
        a >>= 1;
    }
    return ans - 1;
}

ll solve(int n, int k)
{
    
    if (isNumberPowerOf2(k)){
        // cout <<"dfhjhd    ";
        return binaryExponentiationIterativeApproach(n, fu(k) );
    }
    else
    {
        ll nearestPowerof2 = fu(k) - 1;
        // cout<< n<<"  "<<k <<"  nearest power of 2 "<<nearestPowerof2<<"   \n";
        return (binaryExponentiationIterativeApproach(n, fu(k) ) + (solve(n, k - (2 << nearestPowerof2)) % M)) % M;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<int> v(N_local);
    */
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n>> k;
        ll ans = solve(n, k);
        cout << ans << "\n";
    }



    // int as = fu(1);
    // for (int i = 2; i < 1025; i++)
    // {
    //     if (fu(i) != as)
    //     {

    //         cout << i << "   " << fu(i) << "  " << (2 << (fu(i) - 1)) << endl;
    //         as = fu(i);
    //     }
    //     //   cout << i << "   " << fu(i) << 2<<fu(i)<< endl;
    // }

    return 0;
}