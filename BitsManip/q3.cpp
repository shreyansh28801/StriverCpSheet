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
    vector<int> v(n);
    ll sub_ct = 1ll << n;
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin >> v[i];
    }
    bool flag=false;
    for (int i = 0; i < sub_ct; i++)
    {
        ll su=0;
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                    su+=v[j];
            }
            else su-=v[j];
        }
        if(su%360==0){
            cout<<"YES\n";
            flag=true;
            break;
        }
    }
    if(flag==false) cout<<"NO\n";
    

    return 0;
}