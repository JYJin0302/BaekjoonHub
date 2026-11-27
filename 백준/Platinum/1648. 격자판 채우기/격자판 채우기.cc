#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

const int mod = 9901;
int dp[1 << 14];
int tmp[1 << 14];

bool chk(int mask, int pos) {
    return mask & (1 << pos);
}

void solve() {
    int n, m;
    cin >> n >> m;

    if (n * m & 1) {
        cout << 0;
        return;
    }
    if (n > m) swap(n, m);

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            memset(tmp, 0, sizeof(tmp));
            //cout << "Go : " << i << ' ' << j << '\n';
            for (int mask = 0; mask < (1 << m); mask++) {
                if (dp[mask] == 0) continue;

                if (mask % 4 == 0 && j != m-1) {
                    int nm = mask + 3;
                    nm >>= 1;

                    tmp[nm] += dp[mask];
                    tmp[nm] %= mod;
                }

                if (!chk(mask, 0)) {
                    int nm = mask;
                    nm >>= 1;
                    nm += 1 << (m - 1);

                    tmp[nm] += dp[mask];
                    tmp[nm] %= mod;
                }

                if (mask & 1) {
                    int nm = mask;
                    nm >>= 1;

                    tmp[nm] += dp[mask];
                    tmp[nm] %= mod;
                }
            }

            swap(tmp, dp);
        }
    }

    cout << dp[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}