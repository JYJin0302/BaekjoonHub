#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int fact(int n) {
    int ans = 1;
    for (int i = 1; i <= n; i++) ans *= i;
    return ans;
}

ll dp[11][101][101][101];

ll solve(int n, int a, int b, int c) {
    
    if (n == 0) return 1;
    if (dp[n][a][b][c] != -1) return dp[n][a][b][c];
    dp[n][a][b][c] = 0;
    if (n * (n + 1) / 2 > a + b + c) return 0;    

    if (n % 3 == 0) {
        int k = min({ a, b, c });
        if (k >= n / 3) {
            dp[n][a][b][c] += solve(n - 1, a - n/3, b - n/3, c - n/3) * fact(n)/fact(n/3)/fact(n/3)/fact(n/3);
        }
    }
    if (n % 2 == 0) {
        int k;
        k = min(a, b);
        if (k >= n / 2) dp[n][a][b][c] += solve(n - 1, a - n/2, b - n/2, c) * fact(n)/fact(n/2)/fact(n/2);

        k = min(a, c);
        if (k >= n / 2) dp[n][a][b][c] += solve(n - 1, a - n / 2, b, c - n / 2) * fact(n) / fact(n / 2) / fact(n / 2);

        k = min(b, c);
        if (k >= n / 2) dp[n][a][b][c] += solve(n - 1, a, b - n / 2, c - n / 2) * fact(n) / fact(n / 2) / fact(n / 2);
    }

    if (a >= n) dp[n][a][b][c] += solve(n - 1, a - n, b, c);
    if (b >= n) dp[n][a][b][c] += solve(n - 1, a, b - n, c);
    if (c >= n) dp[n][a][b][c] += solve(n - 1, a, b, c - n);

    return dp[n][a][b][c];
}

int main() {

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    memset(dp, -1, sizeof(dp));
    dp[0][0][0][0] = 1;

    

    cout << solve(a, b, c, d);
}