#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& i : A) cin >> i;

    int ans = n;

    vector<int> dp(3);
    for (auto f : A) {
        vector<int> ndp(3);
        ndp[0] = (f != 1) + dp[0];
        ndp[1] = min(dp[0], dp[1]) + (f != 2);
        ndp[2] = min({dp[0], dp[1], dp[2]}) + (f != 3);
        swap(dp, ndp);
    }
    ans = min({ ans, dp[0], dp[1], dp[2] });

    reverse(all(A));
    dp = vector<int>(3);
    for (auto f : A) {
        vector<int> ndp(3);
        ndp[0] = (f != 1) + dp[0];
        ndp[1] = min(dp[0], dp[1]) + (f != 2);
        ndp[2] = min({ dp[0], dp[1], dp[2] }) + (f != 3);
        swap(dp, ndp);
    }

    ans = min({ ans, dp[0], dp[1], dp[2] });
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}