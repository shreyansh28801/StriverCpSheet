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

bool tracker; //if there is any need to visit the current stack to ckeck unmatching pair  parenthesis then it  is true else false



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

    stack<pair<char, int>> st, st1;

    int mx = 0, ans = 0, ct = 0;

    unordered_map<char, int> ump;
    ump['('] = 1;
    ump[')'] = -1;

    int n = s.size();
    vector<bool> vis(n, 0);

    map<int, int> mp;

    //traversal of string for creating visited array to track record about open parenthesis that  will there be any closing bracket of this exixt or not
    for (int i = 0; i < n; i++)
    {
        if (ump[s[i]] == 1)
            st1.push({s[i], i});
        else
        {
            if (st1.empty())
            {
            }
            else if (ump[s[i]] + ump[st1.top().first] == 0)
            {
                // cout<<st1.top().second<<" ";
                vis[st1.top().second] = 1;
                st1.pop();
            }
        }
    }

   
    tracker = false;

    for (int i = 0; i < s.size(); i++)
    {
        if (ump[s[i]] == 1)
        {
            st.push({s[i], i});
            //if corresponding to this opening bracket no closing exixt then mark traker as true 
            if(vis[i]==0) tracker=true;
        }
        else
        {
            if (st.empty())
            {
                mx = 0;
                false;
            }
            else if (ump[st.top().first] + ump[s[i]] == 0)
            {
                mx += 2;
                st.pop();
                if (st.size() > 0&& tracker==true  )
                {
                    mx = 2;
                    //since we are now counting the next RBS hence we need to mark tracker as false to avoid interuption in this due to previous unmatched open parenthesis that are already been taken in considewration.
                    tracker=false;
                    // cout<<st.top().second<<"  ";
                }
                mp[mx]++;
        
            }
        }
    }

   

    if (mp.size() > 0)
    {
        int maxLength = mp.rbegin()->first;
        if (maxLength == 0)
        {
            cout << "0 1";
        }
        else
            cout << maxLength << " " << mp[maxLength];
    }
    else
        cout << "0 1";

    return 0;
}