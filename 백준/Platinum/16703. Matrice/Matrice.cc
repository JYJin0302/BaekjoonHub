#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second

ll dp[1010][1010];

void solve() {

    int n, m;
    cin >> n >> m;

    vector<string> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    ll ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (A[i][j] == A[i - 1][j] && A[i][j] == A[i][j - 1]) {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + 1;
            }
            ans += dp[i][j];
        }
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < n; i++) {
        for (int j = m - 2; j >= 0; j--) {
            if (A[i][j] == A[i - 1][j] && A[i][j] == A[i][j + 1]) {
                dp[i][j] = min(dp[i][j + 1], dp[i - 1][j]) + 1;
            }
            ans += dp[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 1; j < m; j++) {
            if (A[i][j] == A[i + 1][j] && A[i][j] == A[i][j - 1]) {
                dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1;
            }
            ans += dp[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));
    for (int i = n - 2; i >= 0; i--) {
        for (int j = m - 2; j >= 0; j--) {
            if (A[i][j] == A[i + 1][j] && A[i][j] == A[i][j + 1]) {
                dp[i][j] = min(dp[i][j + 1], dp[i + 1][j]) + 1;
            }
            ans += dp[i][j];
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);

    solve();
    return 0;
}
