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
        int o=0,e=0;
        while (n--)
        {
            int x;
            cin>>x;
            if(x&1)     o++;
            else    e++;
        }
        // cout<<o<<"   "<<e<<"       ";
        if(o==0)    cout<<"NO\n";
       else if(o%2 == 0 && e==0)    cout<<"NO\n";
        else    cout<<"YES\n";
        

    }
    
    return 0;
}