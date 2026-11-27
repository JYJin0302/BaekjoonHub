#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int dp[303][303];

void solve() {

    int n, s;
    cin >> s >> n;
    vector<pair<int, int>> A(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i].x >> A[i].y;
        A[i].x += A[i - 1].x;
        A[i].y += A[i - 1].y;
    }

    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            int v2 = A[i].x - A[j].x;

            int tst = A[i].y - A[j].y;
            if (tst > s) continue;
            for (int k = 0; k <= j; k++) {
                int v1 = A[j].y;
                if (k) v1 -= A[k - 1].y;               

                if (v1 + v2 <= s) {
                    dp[j + 1][i] = min(dp[j + 1][i], dp[k][j] + 1);
                }
                else if (v2 <= s) dp[j + 1][i] = min(dp[j + 1][i], dp[k][j] + 2);
            }
        }
    }

    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= n; i++) ans = min(ans, dp[i][n]);
    cout << ans + 1;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}