#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define all(x) x.begin(), x.end()

const ll INF = 1e18;

ll A[2020], C[2020];

ll dp[2020][2020];
ll cost[2020][2020];

ll n, k, p;
// dp[l][l-dif] ~ dp[r][r-dif]
void getDp(int l, int r, int sl, int sr, int dif) {
    if (l > r) return;

    int md = (l + r) >> 1;
    pair<ll, int> res = mp(-INF, -1);

    for (int i = sl; i <= min(sr, md - 1); i++) {
        ll val = dp[i - 1][i - dif] + cost[i + 1][md] + p;
        res = max(res, mp(val, i));
    }

    dp[md][md - dif] = res.first;
    getDp(l, md - 1, sl, res.second, dif);
    getDp(md + 1, r, res.second, sr, dif);
}

void solve() {

    cin >> n >> k >> p;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> C[i];
    }

    for (int i = 1; i <= n; i++) {
        ll val = 0;
        for (int j = 1; i + j <= n + 1; j++) {
            val += A[i + j - 1] * C[j];
            cost[i][i + j - 1] = val;
        }
    }

    for (int i = 1; i <= k; i++) {
        dp[i][i] = cost[1][i] + p;
    }

    for (int dif = 1; dif <= n; dif++) {
        // dp[x][x-dif]
        int l = dif + 1, r = min(n, l + k - 1);
        getDp(l, r, l-1, r - 1, dif);

        for (int j = l; j <= r; j++) {
            dp[j][j - dif] = max(dp[j][j - dif], dp[j - 1][j - dif]);
        }

        /* cout << "Done: " << dif << '\n';
         for (int a = 0; a <= n; a++) {
             for (int b = 0; b <= min(a, (int)k); b++) {
                 cout << dp[a][b] << ' ';
             }
             cout << '\n';
         }
         cout << '\n';*/
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, (int)k); j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}