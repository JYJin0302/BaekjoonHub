#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

int G[1515][1515];
int tG[1515][1515];
int sA[1515][1515];
int getS(int x1, int y1, int x2, int y2) {
    return sA[x2][y2] - sA[x1 - 1][y2] - sA[x2][y1 - 1] + sA[x1 - 1][y1 - 1];
}

int n, m, k;
int ans = 0;
int dp[3][1515][1515];
void getAns() {

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sA[i][j] = G[i][j];
            sA[i][j] += sA[i - 1][j] + sA[i][j - 1] - sA[i - 1][j - 1];
        }
    }

    memset(dp, 0, sizeof(dp));

    for (int i = k; i <= n; i++) {
        for (int j = k; j <= m; j++) {
            dp[0][i][j] = getS(i - k + 1, j - k + 1, i, j);
            dp[0][i][j] = max({ dp[0][i][j], dp[0][i - 1][j], dp[0][i][j - 1] });
        }
    }

    for (int i = k; i <= n; i++) {
        for (int j = k; j <= m; j++) {
            int v = getS(i - k + 1, j - k + 1, i, j);
            dp[1][i][j] = max(dp[0][i - k][j], dp[0][i][j - k]) + v;
            dp[1][i][j] = max({ dp[1][i][j], dp[1][i - 1][j], dp[1][i][j - 1] });
        }
    }

    for (int i = k; i <= n; i++) {
        for (int j = k; j <= m; j++) {
            int v = getS(i - k + 1, j - k + 1, i, j);
            int res = max(dp[1][i - k][n], dp[1][n][j - k]) + v;
            ans = max(ans, res);
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> G[i][j];
        }
    }

    getAns();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            tG[i][j] = G[i][m - j + 1];
        }
    }
    swap(tG, G);
    getAns();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            tG[i][j] = G[n-i+1][j];
        }
    }
    swap(tG, G);
    getAns();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            tG[i][j] = G[i][m - j + 1];
        }
    }
    swap(tG, G);
    getAns();

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}