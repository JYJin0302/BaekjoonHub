#include <bits/stdc++.h>
using namespace std;

const int mod = 10007;

int dp[1001][1001];
int n;
string s;

int solve(int l, int r) {
    if (l < 0 || r > n) return 0;
    if (dp[l][r] != -1) return dp[l][r];

    dp[l][r] = 0;
    if (s[l] == s[r]) {
        dp[l][r] += 1 + solve(l - 1, r + 1);
    }
    dp[l][r] += solve(l, r + 1);
    dp[l][r] += solve(l - 1, r);
    dp[l][r] -= solve(l - 1, r + 1);

    dp[l][r] = (dp[l][r] + mod) % mod;
    return dp[l][r];
}

int main() {

    cin >> s;
    n = s.size();

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (dp[i][j] == -1) {
                solve(i, j);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dp[i][i];
        if (i > 0) ans -= dp[i - 1][i];
        ans = (ans + mod) % mod;
    }

    cout << ans;
}