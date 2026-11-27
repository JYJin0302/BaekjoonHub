#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int len[110];
int dp[101][101];

int lft(int x) {
    return (x + 98) % 100 + 1;
}
int rft(int x) {
    return x % 100 + 1;
}

int solve(int l, int r) {

    if (dp[l][r] != -1) return dp[l][r];
    if (l == r) return dp[l][r] = 0;

    int nl = lft(l);
    int nr = rft(r);
    dp[l][r] = 0;

    if (len[l] == r && len[r] == l) {
        if (nl == r && nr == l) {
            return dp[l][r] = 1;
        }
        return dp[l][r] = 1 + solve(nl, nr);
    }
    if (nl == r && nr == l) {
        return dp[l][r] = 0;
    }

    int i = nl;
    while (i != r) {
        dp[l][r] = max(dp[l][r], solve(l, i) + solve(i, r));
        i = lft(i);
    }
    return dp[l][r];

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= 100; i++) len[i] = 0;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        len[a] = b;
        len[b] = a;
    }

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            dp[i][j] = -1;
        }
    }

    int ans = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            ans = max(ans, solve(i, j));
        }
    }
    cout << ans;
}