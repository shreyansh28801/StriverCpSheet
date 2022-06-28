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
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int i=0,j=1,i1=-1;
    int mx=0;
    while (j<n)
    {
        i1++;
        // cout<<"\n Iter  " << i1<<"  :  ";
        if(v[j]<=v[j-1])    {
            mx=max(mx,(j-i));
            // cout<<1<< "  i and j  "<<i<<"  "<<j<<"  "<<
            // mx <<endl;
            i=j;
            j++;
      
            continue;
        } 
        else j++;
        // cout<<2<< "  i and j  "<<i<<"  "<<j<<"  "<<
        // mx <<endl;
        
    }
        mx=max(mx,(j-i));        
    cout<<mx<<endl;
    


    return 0;
}