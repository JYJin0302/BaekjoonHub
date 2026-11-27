#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t;
    ll mod = 1e9 + 9;
    cin >> t;
    vector<ll> dp(1000001);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= 1000000; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % mod;
    }

    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
}