/***
 * 
 * Blowing up unordered_map, and how to stop getting hacked on it
 * 
 * Blog link  =>https://codeforces.com/blog/entry/62393
 * 
 * 
 * 
 *////


#include <ctime>
#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 2e5;

void insert_numbers(long long x) {
    clock_t begin = clock();
    unordered_map<long long, int> numbers;

    for (int i = 1; i <= N; i++)
        numbers[i * x] = i;

    long long sum = 0;

    for (auto &entry : numbers)
        sum += (entry.first / x) * entry.second;

    printf("x = %lld: %.3lf seconds, sum = %lld\n", x, (double) (clock() - begin) / CLOCKS_PER_SEC, sum);
}

int main() {
    insert_numbers(107897);
    insert_numbers(126271);
}



/*****
 * 
 * 
 * 
 * rsonally, I like to use splitmix64, which is extremely high-quality and fast; credit goes to Sebastiano Vigna for designing it. Adding all this together, we have our safe custom hash function:

struct custom_hash {
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

\n\n\n//Now we can simply define our unordered_map or our gp_hash_table as follows:\n\n//unordered_map<long long, int, csth> safe_map;\n//gp_hash_table<long long, int, csth> safe_hashtable;\n\n\n




Once we use these in our program above, it runs very quickly:

x = 107897: 0.035 seconds, sum = 2666686666700000
x = 126271: 0.031 seconds, sum = 2666686666700000







 * 
 */
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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<ll> v(N_local);
    */ 
    



    return 0;
}