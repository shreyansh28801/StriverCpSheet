#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    int tl_mls = k * l;
    int n_f_packsAvailable = tl_mls / nl;
    int n_f_rd_fpack = n_f_packsAvailable / n;
    int n_f_slices_round = (c * d) / n;
    int n_f_salt_round = (p/np)/n;
    // cout<< tl_mls<<"   "<<n_f_packsAvailable<<"    " <<n_f_rd_fpack<<"  "<<n_f_salt_round<<"    "<<n_f_slices_round<<"\n";
    cout<<min(n_f_rd_fpack,min(n_f_slices_round,n_f_salt_round));

    return 0;
}