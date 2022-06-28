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
    int t;
    cin>>t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int n1=s1.size(),n2=s2.size();
        string r1,r2;
        ll lcm=(n1*n2)/__gcd(n1,n2);
        for (int  i = 0; i < lcm/n1; i++)
        {
            r1+=s1;
        }
        for (int  i = 0; i < lcm/n2; i++)
        {
            r2+=s2;
        }
        if(r1==r2)  cout<<r1<<endl;
        else cout<<"-1\n";
        
    }

    return 0;
}