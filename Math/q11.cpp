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
        int a, b;
        cin >> a >> b;
        int mn = min(a, b);
        int mx = max(a, b);
        a=mn;
        b=mx;


        if ((2 * a) >= b)
            cout << (a * a) * 4 << "\n";
        else    cout<<b*b<<"\n";
    }

    return 0;
}