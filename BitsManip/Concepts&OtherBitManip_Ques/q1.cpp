/*
content to learn this topic => 1. https://www.youtube.com/watch?v=jqJ5s077OKo
2.  https://codeforces.com/blog/entry/73558

In this cpp file we will solve workers ques (Consider this problem: There are N≤5000 workers. Each worker is available during some days of this month (which has 30 days). For each worker, you are given a set of numbers, each from interval [1,30], representing his/her availability. You need to assign an important project to two workers but they will be able to work on the project only when they are both available. Find two workers that are best for the job — maximize the number of days when both these workers are available.)
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

int M = 1e9 + 7;

/*

vector<ll> A(N) ;


*/

const int N = 5e3 + 10;

vector<ull> bitMask(N);

void solve1(int n)
//This solution is valid if maximum no of days worker works are 30
{

    int mx = 0; //mx denotes the the max avilable days b/w 2 workers

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            mx = max(mx, (ll)__builtin_popcountll(bitMask[i] & bitMask[j]));
        }
    }
    cout << mx << endl;
}

int setBit_between_iANdj(vector<ull> &i, vector<ull> &j)
{
    int ans = 0;
    for (int k = 0; k < i.size(); k++)
    {
        ans += (__builtin_popcountll(i[k] & j[k]));
    }
    return ans;
}

void solve2()
//This solution is valid if maximum no of days worker works are 366
{
    int k = (360 / 64) + 1;

    //lets  take input also here
    int n;
    cin >> n;

    vector<vector<ull>> x(n, vector<ull>(k));

    for (int i = 0; i < n; i++)
    {
        //here represents the preson(0 to n-1)
        int m; //no of available days
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int day_no;
            cin >> day_no;
            x[i][(day_no - 1) / 64] &= (1 << (day_no % 64));
        }
    }

    int mx = 0; //mx denotes the the max avilable days b/w 2 workers

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            mx = max(mx, setBit_between_iANdj(x[i], x[j]));
        }
    }
    cout << mx << endl;
}

void solve3()
//doing same problem using bitset class
{
    //lets  take input also here
    int n;
    cin >> n;
    vector<bitset<365>> x;
    x[0]=1;

    for (int i = 0; i < n; i++)
    {
        //here represents the preson(0 to n-1)
        int m; //no of available days
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int day_no;
            cin >> day_no;
            x[i] &= (1 << (day_no - 1));
        }
    }

    ll mxSyncDays = 0; //mx denotes the the max avilable days b/w 2 workers

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int temp=ll((x[i]&x[j]).count());

            mxSyncDays = max(mxSyncDays, temp);
        }
    }
    cout << mxSyncDays << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<ll> v(N_local);
    */
    int n; //no. of workers
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ull x = 0;
        int m; //the no. days ith worker will be availabe
        for (int j = 0; j < m; j++)
        {
            x = (x & (1 << (i + 1)));
        }
        bitMask.pub(x);
    }

    return 0;
}