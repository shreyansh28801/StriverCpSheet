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
    bitset<7> b1;
    cout<<b1<<endl;
    b1[0]=1;
    cout<<b1<<endl;
    b1[1]=1;
    cout<<b1<<endl;
    b1[2]=1;
    cout<<b1<<endl;
    b1[3]=1;
    cout<<b1<<endl;
    b1[3]=0;
    cout<<b1<<endl;
    b1[2]=0;
    cout<<b1<<endl;

    cout<<"hyfryhtfgh       "<<(b1<<2)<<"\n";
    cout<<(b1<<3)<<"\n";
    cout<<(b1<<4)<<"\n";
    cout<<(b1>>1)<<"\n";
    cout<<(b1>>2)<<"\n";
    cout<<(b1>>3)<<"\n";
    cout<<(b1>>3)<<"\n";


    return 0;
}