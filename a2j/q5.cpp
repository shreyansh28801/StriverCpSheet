#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long int li;
typedef long double ld;
#define lb lower_bound 
#define ub upper_bound 
#define pub push_back
#define pob pop_back
typedef long double ld;

/*

const int N = 1e7+10 ;
vector<int> A(N) ;


*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<int> v(N_local);
    */ 
    string s;
    cin>>s;
    int a=0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]<='Z' && s[i]>='A')
        {
            /* code */
            a++;
        }
        
        
    }
    if(a>s.size()-a)    {
        for (int i = 0; i < s.size(); i++)
        {
                if (s[i]<='z' && s[i]>='a')
                {
                    /* code */
                    s[i]=s[i]-'a'+'A';
                }
        }
        
    }
    else{

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i]<='Z' && s[i]>='A')
            {
                /* code */
                s[i]=s[i]+'a'-'A';
            }
        }
    }
    cout<<s<<endl;



    return 0;
}