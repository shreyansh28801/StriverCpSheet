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

int nb, ns, nc;
ll r;
ll r1;
int pb, ps, pc;

bool isSufficientMoneyAvailable(int m, unordered_map<char, int> &um)
{
    int B_req = 0;
    int S_req = 0;
    int C_req = 0;
    for (auto i : um)
    {
        // cout << "\n i " << i.first << "  " << i.second * m << endl;
        if (i.first == 'B')
        {

            B_req = (m * i.second) - nb;
            if (B_req < 0)
                B_req = 0;
        }
        else if (i.first == 'S')
        {

            S_req = (m * i.second) - ns;
            if (S_req < 0)
                S_req = 0;
        }
        else
        {

            C_req = (m * i.second) - nc;
            if (C_req < 0)
                C_req = 0;
        }
    }
    int total_cost = (B_req * pb) + (S_req * ps) + (C_req * pc);
    // cout << "\nb_r  s_r  c_r   toco   " << B_req << "   " << S_req << "    " << C_req << "   " << total_cost << endl;
    r1 = total_cost;
    return total_cost <= r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    const int N_local = 1e5;
    vector<int> v(N_local);
    */

    string s;
    cin >> s;
    unordered_map<char, int> um;
    for (char c : s)
        um[c]++;
    cin >> nb >> ns >> nc;//the number of the pieces of bread, sausage and cheese on Polycarpus' kitchen.
    cin >> pb >> ps >> pc;//the price of one piece of bread, sausage and cheese in the shop
    cin >> r;
    // cout << nb << "  " << ns << "   " << nc << "\n";
    ll costOfOnePeice = 0;// the number of rubles Polycarpus has.
    for (auto i : um)
    {
        if (i.first == 'B')
            costOfOnePeice += (um['B'] * pb);
        else if (i.first == 'S')
            costOfOnePeice += (um['S'] * ps);
        else
            costOfOnePeice += (um['C'] * pc);
    }
    // cout<<"cost of 1 p  "<<costOfOnePeice<<endl;
    int peices_made_by_nb;
    if (um.find('B') != um.end())
        peices_made_by_nb = nb / um['B'];
    else
        peices_made_by_nb = 0;
    // cout<<"cost of 1 p  "<<peices_made_by_nb<<endl;

    int peices_made_by_ns;
    if (um.find('S') != um.end())
        peices_made_by_ns = ns / um['S'];
    else
        peices_made_by_ns = 0;
    // cout<<"cost of 1 p  "<<peices_made_by_ns<<endl;

    int peices_made_by_nc;
    if (um.find('C') != um.end())
        peices_made_by_nc = nc / um['C'];
    else
        peices_made_by_nc = 0;
    // cout<<"cost of 1 p  "<<peices_made_by_nc<<endl;

    int mx = max(peices_made_by_nb, max(peices_made_by_nc, peices_made_by_ns));
    int l = 1, h = mx+1, m;
    while (h - l >= 0)
    {
        m = (l + h) / 2;
        bool temp = isSufficientMoneyAvailable(m, um);
        // cout << h << "  " << l << "   " << m << "  " << temp << endl;
        if (temp)
        {
            l = m + 1;
        }
        else
            h = m - 1;
    }
    // cout << "\n\n\n  r   r1    " << r << "  " << r1 << endl;
    // if (!isSufficientMoneyAvailable(h, um))
    // {
    //     ll ans1 = r / costOfOnePeice;
    //     cout << ans1 << endl;
    //     cout << "\n\n\n  r   r1  ans1   " << r << "  " << r1 << "    " << ans1 << endl;
    // }
    // else
    // {

    r -= r1;
    ll ans1 = r / costOfOnePeice;
    // ll mod_rem=
    // cout<<"\n lasd  "<<ans1<<endl;
    ans1 += h;
    // int h_t=0;
    // if(isSufficientMoneyAvailable(h))   h_t=h;
    // cout << "\n\n\n  r   r1  ans1  h  " << r << "  " << r1 << "    " << ans1 << "   " << h << endl;

    cout << ans1 << endl;
    // }

    return 0;
}