#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

int dp[22][22];
int tmp[22][22];
int INF = 500;

void solve() {

    int n, a, b;
    cin >> n >> a >> b;

    int k;
    cin >> k;
    vector<int> A(k);
    for (auto& i : A) cin >> i;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) dp[i][j] = INF;
    }
    dp[a][b] = 0;

    for (int i = 0; i < k; i++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) tmp[i][j] = INF;
        }

        for (int j = 1; j <= n; j++) {
            for (int a = 1; a <= n; a++) {
                for (int b = 1; b <= n; b++) {
                    tmp[j][A[i]] = min(tmp[j][A[i]], dp[a][b] + min(abs(a - j) + abs(b - A[i]), abs(a - A[i]) + abs(b - j)));
                }
            }
        }
        swap(dp, tmp);
    }
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) ans = min(ans, dp[i][j]);
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