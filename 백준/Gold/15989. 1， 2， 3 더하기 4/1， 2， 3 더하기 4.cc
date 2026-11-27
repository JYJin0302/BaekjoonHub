#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, a, b, c;
    int mod = 1e9 + 9;
    cin >> t;
    vector<vector<int>> dp(1000001, vector<int>(3));
    dp[1] = { 1, 0, 0 };
    dp[2] = { 1, 1, 0 };
    dp[3] = { 1, 1, 1 };
    for (int i = 4; i <= 1000000; i++) {
        dp[i] = { dp[i - 1][0], dp[i - 2][1] + dp[i - 2][0], dp[i - 3][2] + dp[i - 3][1] + dp[i - 3][0] };
    }

    while (t--) {
        int n;
        cin >> n;

        cout << dp[n][0] + dp[n][1] + dp[n][2] << '\n';
    }


}