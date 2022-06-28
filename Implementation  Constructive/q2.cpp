#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, n1;
    cin >> n;
    n1 = n;
    ll nr;
    nr = 0;
    ll p = 1;
    while (n)
    {
        int m = n % 10;
        if (n / 10 == 0 && m == 9)
        {
            nr += (p * m);
            p *= 10;

            n /= 10;
        }
        if (m > 4)
        {
            m = 9 - m;
        }
        nr += (p * m);
        p *= 10;

        n /= 10;
    }
    if (nr == 0)
    {
        cout << n1;
        return 0;
    }

    cout << nr << endl;

    return 0;
}