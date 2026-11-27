#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll dist[101][101];
ll cost[101];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, R;
    cin >> n >> m >> R;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> dist[i + 1][j + 1];
        }
    }

    for (int i = 1; i <= m; i++) cin >> cost[i];

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= m; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }



    vector<int> A(n);
    for (auto& i : A) cin >> i;

    vector<ll> dp(n);
    dp[0] = dist[1][A[0]];
    for (int i = 1; i < n; i++) {
        dp[i] = dist[A[i - 1]][A[i]];
        dp[i] += dp[i - 1];
    }

    int l = 0, r = n - 1;
    ll ans1 = -1, ans2 = -1;
    while (l <= r) {

        int m = (l + r) / 2;
        int ix = 0;

        ll tans = 1e10;
        while (ix + m < n) {
            // i+1 ~ i+m 까지 동료 순회

            ll val = dp[ix] + cost[A[ix]];
            
            if (ix + m < n - 1) {
                val += dist[A[ix]][A[ix + m + 1]] + dp[n-1] - dp[ix+m+1];
            }

            tans = min(tans, val);
            ix++;
        }

        if (tans <= R) {
            ans1 = m;
            ans2 = tans;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    if (ans1 == -1) cout << -1;
    else cout << ans1 << ' ' << ans2;

}