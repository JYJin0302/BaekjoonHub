#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t, a, b, c;
    ll mod = 1e9 + 9;
    cin >> t;
    vector<vector<ll>> dp(1000001, vector<ll>(3));
    dp[1] = { 1, 0, 0 };
    dp[2] = { 0, 1, 0 };
    dp[3] = { 1, 1, 1 };
    for (int i = 4; i <= 1000000; i++) {
        dp[i] = { (dp[i - 1][1] + dp[i - 1][2]) % mod, (dp[i - 2][2] + dp[i - 2][0]) % mod, (dp[i - 3][1] + dp[i - 3][0]) % mod };
    }

    while (t--) {
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1] + dp[n][2]) % mod << '\n';
    }


}