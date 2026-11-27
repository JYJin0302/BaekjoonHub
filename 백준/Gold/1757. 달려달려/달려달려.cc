#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int dp[505][10101];

void solve() {

    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    for (auto& i : A) cin >> i;
    for (int i = 1; i <= n; i++) {
        int v = A[i-1];
        for (int j = 0; j < m; j++) {
            dp[j + 1][i] = max(dp[j + 1][i], dp[j][i - 1] + v);
        }
        dp[0][i] = max(dp[0][i], dp[0][i - 1]);

        for (int j = 1; j <= m && i + j <= n; j++) {
            dp[0][j + i] = max(dp[0][j + i], dp[j][i]);
        }
    }

    cout << dp[0][n];

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}