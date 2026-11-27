#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t, a, b, c;
    ll mod = 1e9 + 9;
    cin >> t;
    vector<ll> dp(1000001);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 2;
    dp[4] = 3;
    dp[5] = 3;
    dp[6] = 6;
    for (int i = 7; i <= 1000000; i++) {
        dp[i] = (dp[i-2] + dp[i-4] + dp[i-6])%mod;
    }

    while (t--) {
        int n;
        cin >> n;

        cout << dp[n] << '\n';
    }


}