#include <bits/stdc++.h>
using namespace std;

int dp[1010][1010][2];
// dp[i][j][k]: s1[0.i], s2[0,j] 의 가장 긴 common suqsequence
// k : s2[j], s2[j-1] swap 여부

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    s1 = '?' + s1 + '?';
    s2 = '?' + s2 + '?';
    if (s1.size() > s2.size()) swap(s1, s2);
    int n = s1.size() - 2, m = s2.size() - 2;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) dp[i][j][0] = dp[i][j][1] = 101010;
    }

    for (int i = 1; i <= max(n, m); i++) {
        dp[0][i][0] = i; dp[0][i][1] = i + 1;
        dp[i][0][0] = i; dp[i][0][1] = i + 1;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {

            dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j - 1][0] + (s1[j] != s2[i]));
            dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j - 1][1] + (s1[j - 1] != s2[i]));
            dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - 1][0] + (s1[j + 1] != s2[i]) + 1);

            if (i > 1) {
                dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0] + 1);
                dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][1] + 1);
            }
            if (j > 1) dp[i][j][0] = min(dp[i][j][0], dp[i][j - 1][0] + 1);
            if (i > 1 && j > 1) dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j - 1][0] + 1);
        }
    }

    cout << dp[m][n][0];

}