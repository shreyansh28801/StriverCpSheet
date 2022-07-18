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

const int N = 1e7 + 10;
vector<int> A(N);

vector<bool> isPrime(N, 1);

void seiveAlgo()
//T . C.  =>  O(N*log(log(N)))
{
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i < N; i++)
    {
        if (isPrime[i] == true)
        {
            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
            }
        }
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
   seiveAlgo();
    int n, m;
    cin >> n >> m;
    int i=n+1;
    while (!isPrime[i])
    {
        i++;
    }
    if(i==m)    cout<<"YES\n";
    else cout<<"NO\n";

    return 0;
}