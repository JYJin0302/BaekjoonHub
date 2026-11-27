#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tcnt = 0;
    int n;
    cin >> n;
    while (n) {
        tcnt++;

        vector<vector<int>> dp(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> dp[i][j];
            }
        }

        dp[0][0] = INF;
        dp[0][2] += dp[0][1];

        for (int i = 1; i < n; i++) {
            
            dp[i][0] += min(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] += min({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i][0] });
            dp[i][2] += min({ dp[i - 1][1], dp[i - 1][2], dp[i][1] });
            
        }

        cout << tcnt << ". " << dp[n - 1][1] << '\n';
        cin >> n;
    }
}