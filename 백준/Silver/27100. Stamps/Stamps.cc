#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int s, e;
    cin >> s >> e;

    vector<int> A(s);
    for (auto& i : A) cin >> i;
    sort(A.begin(), A.end());

    vector<int> dp(10101, e+1);
    dp[0] = 0;
    for (int i = 1; i <= 10010; i++) {
        for (auto j : A) {
            if (i >= j) {
                dp[i] = min(dp[i], dp[i - j] + 1);
            }
        }
    }

    int ans = 0, pv = 1;
    for (int i = 1; i <= 10001; i++) {
        if (dp[i] > e) {
            ans = max(ans, i - pv);
            pv = i + 1;
        }
    }
    cout << ans;
}