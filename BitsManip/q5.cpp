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
    int n, k;
    cin >> n >> k;
    int setBitCount = 0;
    int n1 = n;
    int i = 0;
    multiset<int> s;
    while (n1 > 0)
    {

        if (n1 & 1 == 1)
        {
            s.insert((1 << i));
            setBitCount++;
        }
        i++;

        n1 >>= 1;
    }
    // cout<<"hello";
    if (k < setBitCount)
        cout << "NO\n";
    else{
        // cout<<setBitCount<<endl;
        while(s.size()<k&&*(--s.end())!=1){
            // for(int i:s) cout<<i<<" ";
            int temp=*(--s.end());
            s.erase(--s.end());
            s.insert(temp/2);
            s.insert(temp/2);
            // cout<<"   sz and last   "<<s.size()<<"    "<<*(--s.end());
            // cout<<"\n";
        }
        if(k==s.size()){
            cout<<"YES\n";
            for(int i: s) cout<<i<<" ";
        }
        else cout<<"NO\n";

    }
    

    return 0;
}