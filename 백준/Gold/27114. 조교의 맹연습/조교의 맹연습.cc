#include <bits/stdc++.h>
using ll = long long;
using namespace std;


int dp[1000001][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, k;
    cin >> a >> b >> c >> k;

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < 4; j++) {
            dp[i][j] = k + 10;
        }
    }

    dp[0][0] = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < 4; j++) {
            // Left
            int tj = (j + 3) % 4;
            if (i >= a) dp[i][tj] = min(dp[i][tj], dp[i - a][j]+1);
            tj = (j + 1) % 4;
            if (i >= b) dp[i][tj] = min(dp[i][tj], dp[i - b][j] + 1);
            tj = (j + 2) % 4;
            if (i >= c) dp[i][tj] = min(dp[i][tj], dp[i - c][j] + 1);

        }
    }

    int ans = dp[k][0];
    if (ans == k + 10) ans = -1;
    cout << ans;

}