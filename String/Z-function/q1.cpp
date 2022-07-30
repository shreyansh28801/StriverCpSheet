#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

const int N = 1e6 + 10;

// vector<int> Z_Function(N, 0);

//problem link => https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-interview-prep/text-processing/z-algorithm-for-pattern-searching-official/ojquestion

void zfunction_Optimized(string &s, vector<int> &Z_Function)
//T.C. => O(n)  where n=s.size()
{
    int l = 0;
    int r = 0;
    // vector<int> Z_Function(s.size(), 0);
    for (int i = 1; i < s.size(); i++)
    {
        // cout<<Z_Function[i]<<"  ";
        if (i <= r)
        {
            Z_Function[i] = min(r - i + 1, Z_Function[i - l]);
        }
        while (s[Z_Function[i]] == s[i + Z_Function[i]] && i + Z_Function[i] < s.size())
        {
            Z_Function[i]++;
        }
        // cout<<Z_Function[i]<<"  ";
        if (i + Z_Function[i] - 1 > r)
        {
            l = i;
            r = i + Z_Function[i] - 1;
        }
        // cout<<Z_Function[i]<<"  \n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<ll> v(N_local);
    */

    string s1, s2;
    cin >> s1 >> s2;

    string s = s2 +"#"+ s1;
    // cout << "ujkhjkhgjk\n";


    vector<int> Z_Function(s.size(), 0);
    zfunction_Optimized(s,Z_Function);
    cout<<"\n";
    for(int i: Z_Function)  cout<<i<<"  ";
    cout<<"\n";
    for (int i = 0; i < Z_Function.size(); i++)
    {
        if (Z_Function[i] == s2.size())
            cout << i - s2.size() - 1 << endl;
    }

    return 0;
}