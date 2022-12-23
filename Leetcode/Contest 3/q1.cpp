#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxConsecutive(int bottom, int top, vector<int> &special)
    {
        special.push_back(top);
        special.insert(special.begin(), bottom);
        int ans = 0;
        sort(special.begin(), special.end());
        for (int i = 1; i < special.size(); i++)
        {
            cout << "\n i for ";
            if ((special[i] - special[i - 1]) > 1)
            {
                /* code */
                cout << " i if  ";
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

    Solution o1;
    vector<int> v = {10, 15, 19};
    cout << "   " << o1.maxConsecutive(10, 30, v);
    return 0;
}