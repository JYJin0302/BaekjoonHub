#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

const int mod = 1e8;
int G[15][15];
int gVal[15];
ll dp[15][1 << 15];
bool chk[1 << 15];
void solve() {

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int val = 0;
        for (int j = 0; j < m; j++) {
            cin >> G[i][j];
            val += G[i][j] * (1 << j);
        }
        gVal[i] = val;
    }

    for (int i = 0; i < (1 << m); i++) {
        bool ok = 1;
        for (int f = 1; f < m; f++) {
            if (i & (1 << f) && i & (1 << f - 1)) ok = 0;
        }
        chk[i] = ok;
    }
    

    dp[0][0] = 1;
    for (int j = 1; j <= n; j++) {
        for (int i = 0; i < (1 << m); i++) {
            if ((gVal[j - 1] & i) == i && chk[i]) {
                for (int k = 0; k < (1 << m); k++) {
                    if (i & k) {}
                    else {
                        (dp[j][i] += dp[j - 1][k]) %= mod;
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < (1 << m); i++) {
       (ans += dp[n][i]) %= mod;
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