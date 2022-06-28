#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        if (m > n)
        {
            swap(n, m);
        }
        // cout << n << "   "<< m<<"   " ;
        if (n & 1)
        {
            int ans = ((n - 1) / 2) * m;
            if (m & 1)
            {
                ans += ((m - 1) / 2) + 1;
            }
            else
                ans += ((m ) / 2);
            cout << ans << "\n";
        }
        else
        {
            int ans = ((n) / 2) * m;
            cout << ans << "\n";
        }
    }

    return 0;
}






