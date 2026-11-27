#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[5050][5050][3];

void solve() {

    int n;
    cin >> n;

    vector<string> A(n);
    for (auto& i : A) cin >> i;
    A[0][0] = '0';

    vector<int> L(n+10, n + 1), R(n+10, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == '1') {
                L[i+1] = min(L[i+1], j);
                R[i+1] = max(R[i+1], j);
            }
        }
    }
    for (int i = 0; i <= n; i++) for(int k = 0; k < n; k++) for (int j = 0; j < 3; j++) {
        dp[i][k][j] = 1e8;
    }
    dp[0][0][0] = 0;
    // 0, 1, 2 : from ; up, left, right

    for (int i = 1; i <= n; i++) {

        int lx = L[i], rx = R[i];
        for (int j = 0; j < n; j++) {
            dp[i][j][0] = min({ dp[i - 1][j][0], dp[i - 1][j][1], dp[i - 1][j][2] }) + 1;
            dp[i][j][0] = min(dp[i][j][0], (int)1e8);
        }

        if (lx == rx) {
            for (int j = 0; j <= lx; j++) {
                dp[i][j][1] = dp[i][j][0];
                if (j > 0) dp[i][j][1] = min(dp[i][j][0], dp[i][j - 1][1] + 1);
            }

            for (int j = n - 1; j >= rx; j--) {
                dp[i][j][2] = dp[i][j][0];
                if (j < n - 1) dp[i][j][2] = min(dp[i][j][0], dp [i][j + 1][2] + 1);
            }

            for (int j = lx - 1; j >= 0; j--) {
                dp[i][j][0] = dp[i][j][1] = 1e8;
                dp[i][j][2] = min({ dp[i][j + 1][2], dp[i][j + 1][0] }) + 1;
            }

            for (int j = rx + 1; j < n; j++) {
                dp[i][j][0] = dp[i][j][2] = 1e8;
                dp[i][j][1] = min(dp[i][j - 1][1], dp[i][j - 1][0]) + 1;
            }
        }
        else if (rx != -1) {
            for (int j = 0; j <= lx; j++) {
                dp[i][j][1] = dp[i][j][0];
                if (j > 0) dp[i][j][1] = min(dp[i][j][0], dp[i][j - 1][1] + 1);
            }
            dp[i][rx][1] = dp[i][lx][1] + rx - lx;

            for (int j = n - 1; j >= rx; j--) {
                dp[i][j][2] = dp[i][j][0];
                if (j < n - 1) dp[i][j][2] = min(dp[i][j][0], dp[i][j + 1][2] + 1);
            }
            dp[i][lx][2] = dp[i][rx][2] + rx - lx;

            for (int j = 0; j < n; j++) {
                if (j <= L[i]) {
                    dp[i][j][0] = dp[i][j][1] = 1e8;
                }
                else if (j > L[i] && j < R[i]) {
                    dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = 1e8;
                }
                else if (j >= R[i]){
                    dp[i][j][0] = dp[i][j][2] = 1e8;
                }
            }

            for (int j = lx - 1; j >= 0; j--) {
                dp[i][j][0] = dp[i][j][1] = 1e8;
                dp[i][j][2] = min({ dp[i][j + 1][2], dp[i][j + 1][0] }) + 1;
            }

            for (int j = rx + 1; j < n; j++) {
                dp[i][j][0] = dp[i][j][2] = 1e8;
                dp[i][j][1] = min(dp[i][j - 1][1], dp[i][j - 1][0]) + 1;
            }
        }
        else {
            for (int j = 0; j < n; j++) {
                dp[i][j][1] = dp[i][j][0];
                if (j > 0) dp[i][j][1] = min(dp[i][j][0], dp[i][j - 1][1] + 1);
            }

            for (int j = n - 1; j >= 0; j--) {
                dp[i][j][2] = dp[i][j][0];
                if (j < n - 1) dp[i][j][2] = min(dp[i][j][0], dp[i][j + 1][2] + 1);
            }
        }


    }

    int ans = min({ dp[n][n - 1][0], dp[n][n - 1][1], dp[n][n - 1][2] });
    if (ans == 1e8) ans = -1;
    cout << ans;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
  //  cin >> t;
    while (t--) {
        solve();
    }

}