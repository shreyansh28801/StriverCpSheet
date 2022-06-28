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
        int n, m3 = 0, m2 = 0;
        cin >> n;
        //  n=3*3*2*2*3*2;

        if (1 == n)
        {
            cout << "0\n";
            continue;
        }

        int n1 = n;
        while (n % 3 == 0 && n > 0)
        {
            n /= 3;
            m3++;
        }
        while (n % 2 == 0 && n > 0)
        {
            n /= 2;
            m2++;
        }

        // cout << n1 << "    " << m3 << "   " << m2 << "   ";
        if (n == 1 && m3 > 0)
        {
            int ans;
            if (m3 >= m2)
            {

                ans = 2 * m3 - m2;

                cout << ans << endl;
            }
            else cout<<"-1\n";
        }
        else
            cout << "-1\n";
    }

    return 0;
}