#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int ans = 0;
    while (n--)
    {
        string s;
            
        for (char c : s)
        {
            if (c == '+')
            {
                cout<<"plus";
                ans++;
                break;
            }
            else if (c == '-')
            {
                cout<<"minu";
                ans--;
                break;
            }
        }
    }
    cout << ans << endl;

    return 0;
}