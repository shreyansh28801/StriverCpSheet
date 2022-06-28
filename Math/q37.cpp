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
    int n;
    cin >> n;
    while (n--)
    {
        vector<ll> v(4);
        int even_ct = 0;
        int even_ct1 = 0;
        for (int i = 0; i < 4; i++)
        {
            cin >> v[i];
            if (v[i] % 2 == 0)
                even_ct1++;
            if (i != 3 && v[i] % 2 == 0)
                even_ct++;
        }
        if (all_of(v.begin(), v.end(), [](int x)
                   { return x % 2 == 0; }) ||
            even_ct1 == 3)
            cout << "Yes\n";
        else if (even_ct1 == 3 || even_ct==0    )
            cout << "Yes\n";
        else if (any_of(v.begin(), v.end(), [](int x)
                        { return x == 0; }))
            cout << "No\n";
        // else if(even_ct==2 && v[3]%2==1)     cout<<"Yes\n";
        else if ((even_ct == 1 && v[3] % 2 == 1))
            cout << "Yes\n";
        else
            cout << "No\n";
      
    }

    return 0;
}