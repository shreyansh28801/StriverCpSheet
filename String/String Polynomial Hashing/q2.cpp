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
int M = 1e9 + 7;

const int N = 1e7 + 10;
vector<int> PrefixHashValue(N);
vector<int> dp_PowOfBaseOfString(N);

/* Ques name => Rabin Karp Pattern Find (spoj)
Ques Link =>  https://www.spoj.com/problems/NAJPF/
**/

// ll binaryExponentiation(int a, int b)
// {
//     ll ans = 1;

//     while (b > 0)
//     {
//         if (b & 1 == 1)
//             ans = (ans * 1ll * a) % M;
//         a = (a * 1ll * a) % M;
//         b >>= 1;
//     }
//     return ans;
// }

void RabinKarpRollingHash(string &s)
{
    ll p = 31;
    dp_PowOfBaseOfString[0] = 1;
    PrefixHashValue[0] = (s[0] - 'a' + 1) * dp_PowOfBaseOfString[0];
    for (int i = 1; i < s.size(); i++)
    {
        dp_PowOfBaseOfString[i] = (dp_PowOfBaseOfString[i - 1] * 1ll * p) % M;
        PrefixHashValue[i] = (PrefixHashValue[i - 1] + ((s[i] - 'a' + 1) * 1ll * dp_PowOfBaseOfString[i]) % M) % M;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<int> v(N_local);
    */

    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        ll p = 31;
        ll pow = p;
        ll dhv =(b[0]-'a'+1) ; //desired hash value

        // calclating hash value of b
        for (int i = 1; i < b.size(); i++)
        {
            dhv = (dhv+(b[i] - 'a' + 1) * 1ll * pow) % M;
            pow = (pow * 1ll * p) % M;
        }
        // cout<<"dhv "<<dhv<<endl;

        //now Rabin karp Method Starts

        RabinKarpRollingHash(a);

        vector<int> ans;
        ll count = 0;

        //Using Sliding window kind structure

        int sp = 0, ep = b.size() - 1; //sp , ep are starting and ending point respectively

        while (ep < a.size())
        {
            ll windowhash = PrefixHashValue[ep]; //windowhash represents the hash value  of current window substring
            if (sp > 0)
                windowhash = (windowhash - PrefixHashValue[sp - 1] + M) % M;
            ll Required_dsv = (dhv * 1ll * dp_PowOfBaseOfString[sp]) % M;
            if (Required_dsv == windowhash){

                count++, ans.pub(sp+1);
        }   
            sp++;
            ep++;
        }
        if(ans.size()==0){
            cout<<"Not Found\n\n";
            continue;
        }
        cout << count << endl;
        for (int i : ans)
            cout << i << " ";
        cout << endl;
        cout << endl;

    }

    return 0;
}
