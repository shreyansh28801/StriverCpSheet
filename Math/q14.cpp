#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        if((n/2)%2==1)  cout<<"NO\n";
        else{
            vector<int> v(n);
            for (int i = 0; i < n/2; i++)
            {
                v[i]=2*(i+1);
            }
            for (int i = (n/2); i < n; i++)
            {
                v[i]=v[i-(n/2)]-1;
            }
            v[n-1]+=(n/2);
            cout<<"YES\n";
            for(int i:v)    cout<<i<<" ";
            cout<<"\n";
        }
    }
    
    return 0;
}