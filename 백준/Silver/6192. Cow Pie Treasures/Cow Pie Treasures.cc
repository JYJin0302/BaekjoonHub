#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int n, m;
int G[202][202];
int dp[202][202];
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> G[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = G[0][0];

    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {

            int l = max(0, j - 1);
            int r = min(n - 1, j + 1);

            for (int f = l; f <= r; f++) {
                dp[j][i] = max(dp[j][i], dp[f][i - 1]);
            }
            if (dp[j][i] != -1) dp[j][i] += G[j][i];
        }
    }

    cout << dp[n - 1][m - 1];

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}