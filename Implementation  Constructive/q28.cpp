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

bool vowel(char c)
{
    string s = "AEIOUYaeiouy";
    for (auto ch : s)
        if (ch == c)
            return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<int> v(N_local);
    */
    string s, ans;
    bool a = 0;
    cin >> s;
    // for (auto c : s)
    // {
    //     if (!vowel(c))
    //     {
    //         res.push_back('.');
    //         if (c >= 'A' && c <= 'Z')
    //         {
    //             int i = (c - 'A');
    //             res.push_back('a' + i);
    //         }
    //         else
    //             res.push_back(c);
    //     }
    // }
    // cout << res;

    set<char> s1;
    s1.insert('a');
    s1.insert('e');
    s1.insert('i');
    s1.insert('o');
    s1.insert('u');
    s1.insert('y');


    set<char> s2;
    s1.insert('A');
    s1.insert('E');
    s1.insert('I');
    s1.insert('O');
    s1.insert('U');
    s1.insert('Y');

    for (int i = 0; i < s.size(); i++)
    {
        if (s1.find(s[i]) != s1.end() || s2.find(s[i]) != s2.end())
            a = 1;
        else
        {
            ans.pub('.');
            if (s[i] <= 'Z' && s[i] >= 'A')
                ans.pub(s[i] - 'A' + 'a');
            else
                ans.pub(s[i]);
        }
    }
    cout<<ans<<endl;

    return 0;
}