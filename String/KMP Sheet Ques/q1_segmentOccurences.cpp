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

const int N = 1e6 + 10;

//size of dp_lps shoubd be greater than |s|+|t|+1
vector<ll> A(N);

vector<int> dp_lps(N);
vector<int> occurence(N,0);

void LPS_CleenSolution(string &str)
//this is copy is copied from video solutun
{

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

    // for (int i = 4; i < str.size(); i++)
    // {
    //     cout << dp_lps[i] << "  ";
    // }
    // cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<ll> v(N_local);
    */
    int n, m, q;
    cin >> n >> m >> q;
    string s, t;
    cin >> s >> t;

    //building  a string on which KMP will be applied

    string str = t + "#" + s;

    LPS_CleenSolution(str);



    for (int i = 0; i < s.size(); i++)
    {
        if (dp_lps[i +m + 1] == t.size())
            occurence[i-(m-1)] = 1;
        else
            occurence[i] = 0;
    }
   
    occurence.insert(occurence.begin(),0);

    // for (int i = 0; i < s.size()+1; i++)
    // {
    //     cout << occurence[i] << "  ";
    // }
    // cout << endl;



    for (int i = 1; i <= s.size(); i++)
    {
        occurence[i] += occurence[i - 1];
    }




    // for (int i = 0; i <= s.size(); i++)
    // {
    //     cout << occurence[i] << "  ";
    // }
    // cout << endl;
    // for (int i = 0; i < s.size(); i++)
    // {
    //     cout << i << "  ";
    // }
    // cout << endl;

    while (q--)
    {
        int li, ri;
        cin >> li >> ri;
        if ((ri - li) < m - 1)
        {
            cout << "0\n";
            continue;
        }
        else {
            li--;
            ri=ri-m+1;

            cout<<occurence[ri]-occurence[li];
        }
        cout << endl;
    }

    return 0;
}
