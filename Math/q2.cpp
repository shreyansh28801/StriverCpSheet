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
        int l, r;
        cin >> l >> r;
        long long lcm = (l * 1ll * r) / __gcd(l, r);
        if (lcm > r)
        {
            if ((l * 2) <= r)
                cout << l << " " << 2 * l << endl;
            else
                cout << -1 << " " << -1 << endl;
        }
        else
        {
            cout << l << " " << r << endl;
        }
    }

    return 0;
}