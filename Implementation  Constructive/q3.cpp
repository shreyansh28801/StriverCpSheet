#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n[6][6];
    int r, c;
    for (int i = 1; i < 6; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            int x;
            cin >>x;
            if(x==1){
                r=i;
                c=j;
            }
          
        }
    }
    
    // cout<<r<<"   "<<c<<"   ";
    int ans=abs(3-r)+abs(3-c);
    cout<<ans;

    return 0;
}