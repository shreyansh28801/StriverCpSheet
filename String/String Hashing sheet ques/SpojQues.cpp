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
//doesn't work in case of string to int hashing

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

Ques Link =>  https://www.spoj.com/problems/STRMATCH/

*/



int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<ll> v(N_local);
    */

    int n, q;
    cin >> n >> q;
    string str;
    cin >> str;

    // RabinKarpRollingHash(str);

    map<string, int> StringHashVal;
    unordered_map<int, int, cstH> StringCt;

    for (int i = 0; i < n; i++)
    {
        ll p = 31;   //base of polynomial
        ll pow = 1;  //multiplier of cofficient in current term
        int dhv = 0; //desired hash value (actual value for comparision with value of hashQuery)
        for (int j = i; j < n; j++)
        {
            dhv = (dhv + ((str[j] - 'a' + 1) * pow)) % M;
            pow = (pow * p) % M;

            string stemp = str.substr(i, (j - i + 1));
            StringHashVal[stemp] = dhv;
            StringCt[dhv]++;
        }
    }

    while (q--)
    {
        string test;
        cin >> test;
        cout << StringCt[StringHashVal[test]] << "\n";
    }

    return 0;
}