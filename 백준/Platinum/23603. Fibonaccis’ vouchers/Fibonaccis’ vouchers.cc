#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

ll dp[101][101];

void solve() {

    ll n, k;
    cin >> k >> n;

    ll lim = 1e18;
    vector<ll> fib = { 1, 2 };
    for (int i = 2; ; i++) {
        fib.push_back(fib[i - 1] + fib[i - 2]);
        if (fib.back() > lim) break;
    }

    int sz = fib.size();
    for (int j = 0; j < sz; j++) dp[1][j] = 1;

    for (int i = 2; i <= k; i++) {
        for (int j = 2; j < sz; j++) {
            for (int k = 0; k < j - 1; k++) {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < sz; j++) {
            if (j) dp[i][j] += dp[i][j - 1];
            if (i > 1) dp[i][j] += dp[i - 1][j];
            if (j && i > 1) dp[i][j] -= dp[i - 1][j - 1];
        }
    }


    /*for (int i = 1; i <= k; i++) {
        for (int j = 0; j < sz; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }*/

    ll val = 0;
    ll cur = n + k - 1;
    for (int i = k; i >= 1 && cur; i--) {
        int ix = 0;
        while (ix < sz && dp[i][ix] < cur) ix++;

        if (ix == sz) {
            cout << "NIE\n";
            return;
        }
        val += fib[ix];
        if (val > (ll)1e18) {
            cout << "NIE\n";
            return;
        }

        if (ix) cur -= dp[i][ix - 1];
        cur--;
    }

    cout << val << '\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}