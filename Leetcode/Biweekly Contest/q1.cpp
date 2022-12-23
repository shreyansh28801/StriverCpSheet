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

const int N = 1e6+10 ;
vector<ll> A(N) ;


*/

// int minimumOperations(vector<int> &v)
// {
//     int ct = 0;
//     sort(v.begin(), v.end());
//     auto it = upper_bound(v.begin(), v.end(), 0);
//     if (it == v.end())
//         return 0;
//     else
//     {
//         ct = *(v.end() - 1) / (*it);
//         if (*(v.end() - 1) % (*it) != 0)
//             ct++;
//     }

//     return ct;
//}

int minimumOperations(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    // cout<<any_of(nums.begin(), nums.end(), [](int x)
    // { return x != 0; })<<"  "<<"   "<<*(upper_bound(nums.begin(), nums.end(), 0));
    int j = 1;
    int ct = 0;
    while (any_of(nums.begin(), nums.end(), [](int x)
                  { return x != 0; }))
    {
        /* code */
        auto it = upper_bound(nums.begin(), nums.end(), 0);
        int p = (*it);
        for (int i = 0; i < nums.size(); i++)
        {
            // cout<<nums[i]<<"   ";
            if (nums[i] != 0)
                nums[i] -= p;
        }
        ct++;
        // cout << "\n"<< (*it) << "  " << ct << endl;
        // cin>>i;
        j++;
    }
    return ct;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<ll> v(N_local);
    */
    vector<int> nums = {1,2,3,4,5,6,7};
    // sort(nums.begin(), nums.end()

    cout<<minimumOperations(nums);

    return 0;
}