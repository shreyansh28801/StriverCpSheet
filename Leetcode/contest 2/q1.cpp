#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int divisorSubstrings(int num, int k)
    {
        string s = to_string(num);
        int ans = 0;
        for (int i = 0; i <= s.size() - k; i++)
        {
            // cout<<"\n hello \n";
            string r = s.substr(i, k);
            r.erase(0, r.find_first_not_of('0'));
            if (r.size() == 0)
            {
                continue;
            }
            stringstream geek(r);
            int x = 0;
            geek >> x;

            if (num % x == 0)
            {

                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s1;
    cout<<"ans is  "<<s1.divisorSubstrings(30003,3);

    return 0;
}