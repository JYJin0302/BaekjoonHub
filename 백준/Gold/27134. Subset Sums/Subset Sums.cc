#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()



void solve() {

    int n;
    cin >> n;

    int tot = n * (n + 1) / 2;
    if (tot & 1) {
        cout << 0 << '\n';
        return;
    }

    vector<ll> dp(tot + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = tot; j >= i; j--) {
            dp[j] += dp[j - i];
        }
    }
    cout << dp[tot / 2]/2 << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}