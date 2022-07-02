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
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;

    while (t--)
    {
        int found = s.find("BG");
        // cout<<found<<endl;
        while (found != std::string::npos)
        {
            // cout<<s<<"   "<<found<<"  " <<found+2<<"   "<<s.size() <<endl;
            s.insert(found + 2, "GB");
            s.erase(s.begin() + found, s.begin() + found + 2);

            if (found + 2 >= s.size()-1){
                // cout<<"hello\n";
                break;
            }
            else
                found = s.find("BG", found + 2);
        }
        // cout<<s<<"jkghjhkg\n";
    }
        // cout<<s<<"   "<<found<<endl;
        cout << s << endl;

    return 0;
}