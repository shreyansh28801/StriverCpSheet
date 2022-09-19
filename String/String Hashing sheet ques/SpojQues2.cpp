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
istream &operator>>(istream &input, vector<T> &v) {
    for (auto &i : v) cin >> i;
    return input;
}


template <typename T>
ostream &operator<<(ostream &output, vector<T> &v) {
    for (auto &i : v) cout << i<<" ";
    return output;
}


//Definition of custom hash function to avoid collision in malicious test-cases (aka hacked test-cases)

struct cstH {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

//Now we can simply define our unordered_map or our gp_hash_table as follows:
//unordered_map<long long, int, cstH> safe_map;
//gp_hash_table<long long, int, cstH> safe_hashtable;

int M=1e9+7;

/*

const int N = 1e6+10 ;
vector<ll> A(N) ;


*/

const int N = 1e6 + 10;
vector<int> PrefixHashValue(N);
vector<int> dp_PowOfBaseOfString(N);


void RabinKarpRollingHash(string &s)
{
    ll p = 31;
    dp_PowOfBaseOfString[0] = 1;
    PrefixHashValue[0] = (s[0] - 'a' + 1) * dp_PowOfBaseOfString[0];

    for (int i = 1; i < s.size(); i++)
    {
        dp_PowOfBaseOfString[i] = (dp_PowOfBaseOfString[i - 1] * p) % M;
        PrefixHashValue[i] = (PrefixHashValue[i - 1] + ((s[i] - 'a' + 1) * dp_PowOfBaseOfString[i]) % M) % M;
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
            ll Required_dsv = (dhv  * dp_PowOfBaseOfString[sp]) % M;
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