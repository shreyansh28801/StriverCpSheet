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
        // cout << t << "   ";
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        vector<int> v(3);
        v[0] = a;
        v[1] = b;
        v[2] = c;

        sort(v.begin(), v.end());
        // for (int i : v)
        //     cout << i << "   ";
        // cout << "\n";

        int te = 2 * (v[2] - v[1]);
        te += (v[1] - v[0]);
        if (n % 3 == 0 && v[0] == v[1] && v[1] == v[2])
        {
            cout << "YES\n";
        }

        else if (n >= te)
        {
            n -= te;
            if (n % 3 == 0)
                cout << "YES\n";
            else
                cout << "NO\n";
        }

        else
            cout << "NO\n";
    }

    return 0;
}