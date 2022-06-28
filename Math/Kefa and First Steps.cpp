#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        v[i]=x;
    }
    int mx=1;
    int ct=1;
    int i=1;
    while(i<n){
        // cout<<i<<"   "<<ct<<"   "<<mx<<endl;
        if(v[i]>=v[i-1])    ct++;
        else    {
            ct=1;
        }
        mx=max(mx,ct);
        i++;
    }
    cout<<mx<<endl;
    
    return 0;
}