#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll dp[22][22];
ll f[22];
ll c[22][22];

ll solve(int n, int cnt) {
    if (dp[n][cnt] != -1) return dp[n][cnt];
    if (cnt == 0 || n == 0) {
        if (n + cnt == 0) return dp[n][cnt] = 1;
        return dp[n][cnt] = 0;
    }
    if (cnt > n) return dp[n][cnt] = 0;
    ll res = 0;

    for (int i = 0; i < n; i++) {
        res += c[n-1][i]*f[i] * solve(n - 1 - i, cnt - 1);
    }
    return dp[n][cnt] = res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(dp, -1, sizeof(dp));

    f[0] = 1;
    for (int i = 1; i <= 20; i++) {
        f[i] = f[i - 1] * i;
    }

    c[0][0] = 1;
    c[1][0] = 1;
    c[1][1] = 1;
    for (int i = 2; i <= 20; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }

    int t;
    cin >> t;
    while (t--) {

        int n, l, r;
        cin >> n >> l >> r;

        ll ans = 0;

        for (int i = 0; i < n; i++) {
            // maximum here
            ans += solve(i, l - 1) * solve(n - 1 - i, r - 1) * c[n-1][i];
            //cout << "MUL: " << i << ' ' << l - 1 << " * " << n - 1 - i << ' ' << r - 1 << '\n';
            //cout << solve(i, l - 1) << ' ' << solve(n - 1 - i, r - 1) << '\n';
        }
        cout << ans << '\n';

    }

}