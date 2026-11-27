#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

const int MOD = 1e6;

void solve() {

    int t, a, s, b;
    cin >> t >> a >> s >> b;

    vector<int> cnt(t + 1);
    for (int i = 0; i < a; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    vector<int> dp(a + 1);
    dp[0] = 1;
    for (int i = 1; i <= t; i++) {
        vector<int> tmp(a + 1);
        for (int j = 0; j <= a; j++) {
            tmp[j] = dp[j];
            if (j) tmp[j] += tmp[j - 1];
            tmp[j] %= MOD;
        }

        for (int j = 0; j <= a; j++) {
            if (j > cnt[i]) dp[j] = tmp[j] - tmp[j - cnt[i] - 1];
            else dp[j] = tmp[j];
            dp[j] = (dp[j] % MOD + MOD) % MOD;
        }
    }

    int ans = 0;
    for (int i = s; i <= b; i++) {
        ans += dp[i];
        ans %= MOD;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}