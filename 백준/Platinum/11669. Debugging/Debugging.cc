#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair


ll n, r, p;

ll dp[1010101];


ll getVal(ll x) {
    if (dp[x] != -1) return dp[x];
    if (x == 1) return dp[x] = 0;

    ll res = r + p*(x-1);

   // cout << "CURr: " << x << "\n";

    for (ll i = 2; i < x; ) {
        ll tx = (x + i - 1) / i;
       // cout << "Go: " << x << ' ' << i << ' ' << tx << '\n';

        res = min(res, getVal(tx) + r + (i - 1) * p);
       
        if (tx == 1) break;
        ll ni = (x + tx-2) / (tx-1);
        if (ni <= i) break;
        i = ni;
    }

    return dp[x] = res;
}

void solve() {
    cin >> n >> r >> p;

    memset(dp, -1, sizeof(dp));

    cout << getVal(n);


}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
  //  cin >> t;
    while (t--) {
        solve();
    }
}