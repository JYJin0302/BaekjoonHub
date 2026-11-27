#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

ll ans[22];


void solve() {

    int n;
    cin >> n;

    if (ans[n]) {
        cout << ans[n] << '\n';
        return;
    }

    vector<ll> dp(n + 1);
    // dp[i] : 마지막에 선택한 것이 i번째 수였다
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        vector<ll> tdp(n + 1);
        if (!(i & 1)) {
            // go up

            for (int j = 0; j <= n; j++) {
                if (!dp[j]) continue;

                int len = n - i - j;
                for (int f = 0; f < len; f++) {
                    tdp[f + j] += dp[j];
                }
            }
            
        }
        else {
            // go down
            for (int j = 0; j <= n; j++) {
                if (!dp[j]) continue;

                int len = j;
                for (int f = 0; f < len; f++) {
                    tdp[f] += dp[j];
                }
            }
        }

        swap(dp, tdp);
    }

    ll tot = 0;
    for (auto f : dp) tot += f;
    if (n == 1) ans[n] = 1;
    else ans[n] = 2 * tot;
    cout << ans[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
     cin >> t;
    while (t--) solve();
}