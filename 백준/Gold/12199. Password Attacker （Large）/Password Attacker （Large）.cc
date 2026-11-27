#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int mod = 1e9 + 7;

ll C[202][202];
ll H(int n, int r) {
    return C[n + r - 1][r];
}

ll D[101][101];

void solve() {

    int n, m;
    cin >> m >> n;

    vector<ll> dp(n + 1, 1), tmp(n + 1);
    dp[0] = 0;

    for (int i = 1; i < m; i++) {
        tmp = vector<ll>(n + 1);
        for (int j = i; j <= n; j++) {
            for (int k = 1; k + j <= n; k++) {
                (tmp[j + k] += dp[j] * D[j + 1][k] % mod) %= mod;
            }
        }
        swap(tmp, dp);
    }

    cout << dp[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    C[0][0] = 1;
    C[1][0] = C[1][1] = 1;
    for (int i = 2; i <= 200; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            for (int f = 1; f <= j; f++) {
                (D[i][j] += C[i][f] * H(f, j - f) % mod) %= mod;
            }
        }
    }

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}