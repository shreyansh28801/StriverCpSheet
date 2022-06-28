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

int r;

bool isFeasible(int m, vector<int> &a, vector<int> &b, int k)
{
    int totalGramsExtraNeeded = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int temp = (m * a[i]) - b[i];
        if (temp < 0)
            continue;
        else
            totalGramsExtraNeeded += temp;
    }
    r = totalGramsExtraNeeded;
    return totalGramsExtraNeeded <= k;
}

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
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = b[i] / a[i];
        mx = max(mx, temp);
    }
    int s = 1, e = mx + 1, m;
    while (e - s >= 0)
    {
        m = (s + e) / 2;
        if (isFeasible(m, a, b, k))
        {
            s = m + 1;
        }
        else
            e = m - 1;
    }

    int ans = 0;
    if (isFeasible(e, a, b, k))
    {
        ans = e;
        k -= r;
    }

    int GramsFor1Toast = accumulate(a.begin(), a.end(), 0);
    ans+=(k/GramsFor1Toast);
    cout<<ans<<endl;

    return 0;
}