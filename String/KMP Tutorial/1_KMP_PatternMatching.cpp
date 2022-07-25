/*
we will aplly kmp 1st on this problem on this problem => https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-interview-prep/text-processing/kmp-pattern-searching-official/ojquestion

To solve this problem we will solve one prblem name lps(longest prefix suffix) Problem LInk => https://leetcode.com/problems/longest-happy-prefix/
 
this problem is solved in file => 2_LongestPrefixSuffix.cpp

***/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long int li;
#define int long long int
typedef long double ld;
#define lb lower_bound
#define ub upper_bound
#define pub push_back
#define pob pop_back
typedef long double ld;

int M = 1e9 + 7;

/*

const int N = 1e7+10 ;
vector<ll> A(N) ;


*/

void LPS_CleenSolution(string &str,int sz)
//this is copy is copied from video solutun
{
    vector<int> dp_lps(str.size());

    dp_lps[0] = 0;

    int i = 1;   //index to iterate
    int len = 0; //len denotes the dp_lps[i-1]
    while (i < str.size())
    {
        if (str[i] == str[len])
        {
            len++;
            dp_lps[i] = len;
            i++;
        }
        else
        {
            if (len > 0)
                len = dp_lps[len - 1];
            else
            {
                dp_lps[i] = 0;
                i++;
            }
        }
    }
     for (int i : dp_lps)
        cout << i << " ";
    cout << "\n";
  
    for (int i = sz+1; i < dp_lps.size(); i++)
    {
        // cout<<"hjdsk\n";
        if(dp_lps[i]==sz) cout<<(i-(2*sz))<<endl;
    }
    
    
}


int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<ll> v(N_local);
    */


    string s1, s2;//we have to find patetrn s1 in s2
    cin >> s1 >> s2;

    string s=s2+"#"+s1;
    //now appy lps in s
    

    LPS_CleenSolution(s,s2.size());
   

    return 0;
}
