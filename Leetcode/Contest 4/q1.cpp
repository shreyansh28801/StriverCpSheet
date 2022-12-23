#include <bits/stdc++.h>
using namespace std;
double calculateTax(vector<vector<int>> &brackets, int income)
{
    double ans=0;
    int prev=0;
    for(auto i:brackets){
        if (i[0]<income)
        {
            ans+=   (i[0]-prev)*((double)i[1]/100);
        }
        else{
            ans+=   (income-prev)*((double)i[1]/100);
            break;
        }
        
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}