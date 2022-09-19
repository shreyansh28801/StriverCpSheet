#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long int li;
#define int long long int
typedef long double ld;
#define lb lower_bound
#define ub upper_bound
#define pub push_back
#define pob pop_back
typedef long double ld;

template <typename T>
istream &operator>>(istream &input, vector<T> &v)
{
    for (auto &i : v)
        cin >> i;
    return input;
}

template <typename T>
ostream &operator<<(ostream &output, vector<T> &v)
{
    for (auto &i : v)
        cout << i << " ";
    return output;
}

//Definition of custom hash function to avoid collision in malicious test-cases (aka hacked test-cases)

struct cstH
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

//Now we can simply define our unordered_map or our gp_hash_table as follows:
//unordered_map<long long, int, cstH> safe_map;
//gp_hash_table<long long, int, cstH> safe_hashtable;

int M = 1e9 + 7;

/*

const int N = 1e6+10 ;
vector<ll> A(N) ;


*/

void pwd(stack<string> st)
{
    string ans;

    if (st.size() == 0)
    {

        ans.pub('/');
        cout << ans << endl;
    }
    else
    {

        while (st.size() > 0)
        {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        ans.pub('/');
        cout << ans << endl;
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
    int n;
    cin >> n;
    string str;
    stack<string> st;

    while (n--)
    {
        getline(cin, str);

        // Keep reading a new line while there is
        // a blank line
        while (str.length() == 0)
            getline(cin, str);

        // cout << str <<endl;

        if (str == "pwd")
        {
            pwd(st);
        }
        else
        {
            // if (str[str.size() - 1] != '/')
            str.pub('/');

            string temp;

          
            if (str[3] == '/')
            {
                while (st.size() > 0)
                {
                    // cout<<st.top()<<"  ";
                    st.pop();
                }
                // cout<<"\n";
            }

            for (int i = 3; i < str.size(); i++)
            {

                if (str[i] != '/')
                    temp.pub(str[i]);

                else
                {
                    if (temp == "" || temp == ".")
                    {
                        //ignore
                    }
                    else if (temp == "..")
                    {
                        if (!st.empty())
                            st.pop();
                    }
                    else
                    {
                        st.push(temp);
                    }

                    temp = "";
                }
            }
        }
    }

    return 0;
}