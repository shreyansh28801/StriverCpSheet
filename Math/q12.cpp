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
        int n;
        cin>>n;
        vector<int> v(n);
        int o=0,e=0;
        for (int i = 0; i < n; i++)
        {
            // cin>>v[i];
            int x;
            cin>>x;
            v[i]=x;
            
        }
        for (int i = 0; i < n; i++)
        {
            if(i%2!=v[i]%2){
                if(i%2==0)  e++;
                else    o++;
            }

        }

        if(o==e)   cout<<o<<endl;
        else    cout<<"-1\n";

        
    } 
    return 0;
}