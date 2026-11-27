#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

ll dp[101010];

void solve() {

    int n;
    cin >> n;

    vector<ll> A(n + 10);
    for (int i = 1; i <= n; i++) cin >> A[i];

    ll ans = 0;

    dp[1] = A[2];
    dp[2] = A[1] + A[3];

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 2] + A[i + 1];
        if (i - 3 > 0) dp[i] = max(dp[i], dp[i - 3] + A[i - 1] + A[i + 1]);
    }

    cout << *max_element(dp, dp + n + 1);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}