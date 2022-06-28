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
    ll n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        int isEven = 0;
        int ZeroCt = 0;
        ll SumOfDigit = 0;
        for (char c : s)
        {
            int te = c - '0';
            SumOfDigit += te;

            if (te % 2 == 0)
                isEven ++;
            if (0 == te)
                ZeroCt++;
        }
        // cout<<SumOfDigit<<"  "<<ZeroCt<<"  "<<isEven<<endl;
        if (SumOfDigit % 3 == 0 && ZeroCt > 0 && isEven >1)
            cout << "red\n";
        else
            cout << "cyan\n";
    }

    return 0;
}