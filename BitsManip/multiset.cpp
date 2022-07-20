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

    multiset<int> ms;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ms.insert(x);
    }
    for(int i:ms) cout<<i<<"  ";
    cout<<"\n";
    cout<<*(--ms.end())<<endl;
    ms.erase(--ms.end());//erasing by pointer erases only one value
   // ms.erase(*(--ms.end()));//erasing by value erases all elements that has same value
    for(int i:ms) cout<<i<<"  ";
    cout<<"\n";

    return 0;
}