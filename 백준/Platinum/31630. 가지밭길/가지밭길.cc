#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


int n, m, k;
ll dp[5050][5050];
bool chk[5050][5050];
const ll mod = 1e9 + 7;

void solve() {

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        int x, y; cin >> x >> y;
        chk[x][y] = 1;
    }

    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i + j == 0 || chk[i][j]) continue;
            if (i) dp[i][j] += dp[i - 1][j];
            if (j) dp[i][j] += dp[i][j - 1];
            if (i && j && !chk[i-1][j] && !chk[i][j-1]) dp[i][j] -= dp[i - 1][j - 1];
            dp[i][j] = (dp[i][j] + mod) % mod;
        }
    }

    cout << dp[n][m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}