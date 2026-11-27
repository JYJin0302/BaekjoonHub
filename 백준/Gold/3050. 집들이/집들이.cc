#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int G[404][404];

void solve() {

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c == '.') G[i][j] = 0;
            else G[i][j] = 1;

            G[i][j] += G[i][j - 1];
        }
    }

    int ans = 0;
    for (int l = 1; l <= m; l++) {
        for (int r = l; r <= m; r++) {

            int cur = 0;
            for (int j = 1; j <= n; j++) {
                if (G[j][r] - G[j][l - 1] == 0) cur++;
                else {
                    if (cur) ans = max(ans, 2 * (cur + r - l + 1));
                    cur = 0;
                }
            }
            if (cur) ans = max(ans, 2 * (cur + r - l + 1));
        }
    }

    if (ans) cout << ans - 1;
    else cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}