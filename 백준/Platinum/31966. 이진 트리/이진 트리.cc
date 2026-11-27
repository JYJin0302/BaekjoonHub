#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int mod = 1e9 + 7;
ll dp[3][101010];
ll sz[101010];

void solve() {

    int n;
    cin >> n;

    vector<pair<int, int>> A(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i].x >> A[i].y;
    }

    dp[0][0] = dp[1][0] = dp[2][0] = 1;
    sz[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        auto [l, r] = A[i];

        dp[0][i] = (dp[2][l] * sz[r] + dp[1][r] * sz[l] + dp[0][l] + dp[0][r] - 1) % mod;
        dp[1][i] = (dp[1][l] + dp[1][r] + sz[r] - 1) % mod;
        dp[2][i] = (dp[2][r] + dp[2][l] + sz[l] - 1) % mod;
        sz[i] = (sz[l] + sz[r]) % mod;

        cout << dp[0][i] << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}