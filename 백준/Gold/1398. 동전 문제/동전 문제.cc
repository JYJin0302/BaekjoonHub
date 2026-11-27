#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    vector<int> dp(100, 101);
    dp[0] = 0;
    for (int i = 1; i < 100; i++) {
        dp[i] = min(dp[i], dp[i - 1] + 1);
        if (i >= 10) dp[i] = min(dp[i], dp[i - 10] + 1);
        if (i >= 25) dp[i] = min(dp[i], dp[i - 25] + 1);
    }


    while (t--) {

        ll x;
        cin >> x;

        int ans = 0;
        while (x) {

            ll tx = x % 100;
            ans += dp[tx];
            x /= 100;
        }
        cout << ans << '\n';
    }

}