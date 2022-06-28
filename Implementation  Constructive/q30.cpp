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
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> val;
        for (int i = 1; i <= n; i++)
            val.push_back(i);
        vector<int> res;
        while (val.size() > 1)
        {
            int s = val.size();
            int sum = val[s - 1] + val[s - 2];
            res.push_back(val[s - 1]);
            res.push_back(val[s - 2]);
            val.pop_back();
            val.pop_back();
            if (sum % 2 == 1)
                val.push_back((sum /2) + 1);
            else
                val.push_back(sum / 2);
        }
        cout << val.back() << endl;
        for (int i = 0; i < res.size(); i += 2)
            cout << res[i] << " " << res[i + 1] << endl;
    }

    return 0;
}