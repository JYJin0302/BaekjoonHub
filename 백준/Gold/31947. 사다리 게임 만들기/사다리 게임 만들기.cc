#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    int n, m;
    cin >> n >> m;

    int s, e;
    cin >> s >> e;
    s--, e--;
    vector<ld> dp(n), tmp(n);
    dp[s] = 1;
    while (m--) {
        tmp = vector<ld>(n);

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            if (i) {
                tmp[i] += dp[i - 1] * 1.0 / (n - 1);
                cnt++;
            }
            if (i + 1 < n) {
                tmp[i] += dp[i + 1] * 1.0 / (n - 1);
                cnt++;
            }

            tmp[i] += dp[i] * 1.0 * (n - 1 - cnt) / (n - 1);
        }
        swap(dp, tmp);
    }
    cout << setprecision(15);
    cout << dp[e] << '\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
   // cin >> t;
    while (t--) solve();
}