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
        int n, x;
        cin >> n >> x;
        // cout << "for " << n << "   " << x << "    ";
        if (n < 3)
        {
            cout << "1\n";
            continue;
        }
        int y1, y2;
        y1 = (n + (2 * x) - 3) / x;
        y2 = (n + x - 2) / x;
        // cout << y1 << "     " << y2 << "   ";
        int mn = min(y1, y2);
        int mx = max(y1, y2);
        y1 = mn;
        y2 = mx;
        // cout<<mn<<"  "<<mx<<endl;
        while (y1 <= y2)
        {
            int s = ((y1 - 2) * x) + 3;
            int e = ((y1 - 1) * x) + 2;
            if (n >= s && n <= e)
            {
                // cout << s << "     " << e << "   " << endl;
                cout << y1 << endl;
            }
            y1++;
        }
    }

    return 0;
}