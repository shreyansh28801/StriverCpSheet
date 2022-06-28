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

/*

const int N = 1e7+10 ;
vector<int> A(N) ;


*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<int> v(N_local);
    */
    ll n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    if (arr[n - 2] + arr[n - 3] <= arr[n - 1])
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        cout << arr[n - 1] << " ";
        for (int i = n - 3; i >= 0; i--)
            cout << arr[i] << " ";
        cout << arr[n - 2] << endl;
    }

    return 0;
}