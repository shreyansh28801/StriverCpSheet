/*
To understand kmp we will do it through lps(longest prefix)
Problem LInk => https://leetcode.com/problems/longest-happy-prefix/
Note - 
1. prefix and suffix here are proper prefix and proper suffix(basically if we won't consider proper then ans would always be  string itself)
2. prefix and suffix are considered w.r.t. increasing order of indexes
3. overlaping in prefix and suffix is possible
4. if we want to this problem using constant space then we should do it using Rabin karp rolling hashing(video link=> https://www.youtube.com/watch?v=8f_JcbwoBQY&list=PL-Jc9J83PIiEoZSwjEZT3TvpKG16FntFL&index=14)
*/

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

string LPS(string &str)
//My Coded Solution after long debugging
{
    //cout<<str.size();
    vector<int> dp_lps(str.size());
    // cout<<str.size()<<endl;
    dp_lps[0] = 0;
    for (int i = 1; i < str.size(); i++)
    {
        // dp_lps[i] =str[dp_lps[i-1]]==str[i]?dp_lps[i-1]+1:0; it would be ans but some extra logic in negation case so we do it through if-else
        // cout << "wow\n";
        if (str[dp_lps[i - 1]] == str[i])
        {
            dp_lps[i] = 1 + dp_lps[i - 1];
        }
        else
        {
            if (dp_lps[i - 1] == 0)
            {
                // cout<<"dsafhjk";
                dp_lps[i] = 0;
                continue;
            }
            int len = dp_lps[dp_lps[i - 1] - 1];
            // cout<<i<<" bahar " <<len<<endl;
            while (len > 0)
            {
                // cout<<i<<"  " <<len<<endl;
                if (str[len] == str[i])
                {
                    dp_lps[i] = len + 1;
                    break;
                }
                else
                    len = dp_lps[len - 1];
            }
            if (len == 0)
            {
                // cout<<"dsfhjk\n";
                if (str[0] == str[i])
                    dp_lps[i] = 1;
                else
                    dp_lps[i] = 0;
            }
        }
    }
    // for (int i : dp_lps)
    //     cout << i << "  ";
    // cout << "\n";
    // auto ans = max_element(dp_lps.begin(), dp_lps.end());
    // int a = *ans;
    string ret(str.begin(), str.begin() + dp_lps[str.size() - 1]);
    return ret;
}

string LPS_CleenSolution(string &str)
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
    string ret(str.begin(), str.begin() + dp_lps[str.size() - 1]);
    return ret;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<ll> v(N_local);
    */

    string s;
    cin >> s;

    return 0;
}