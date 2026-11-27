#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> A(m);
    for (auto& i : A) cin >> i;

    vector<int> B(n+1);
    for (int i = 1; i <= n; i++) cin >> B[i];

    int maxV = 100000;
    vector<int> dp(maxV + 1, maxV+10);
    dp[0] = 0;
    for (int i = 1; i <= maxV; i++) {
        for (auto j : A) {
            if (i - j >= 0) {
                dp[i] = min(dp[i], dp[i - j] + 1);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int v = B[i] - max(0, B[i - 1] - 1);
        ans += dp[v];
        if (dp[v] > maxV) {
            cout << -1;
            return 0;
        }
    }
    cout << ans;

}