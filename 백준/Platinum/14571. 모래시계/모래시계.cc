#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool conn[201][201];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        conn[a][b] = 1;
        conn[b][a] = 1;
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) {

        int tot = 0;
        vector<ll> cnt(n + 1);

        for (int j = 1; j <= n; j++) {
            for (int k = j+1; k <= n; k++) {
                if (conn[i][j] && conn[i][k] && conn[j][k]) {
                    cnt[j]++, cnt[k]++, tot++;
                }
            }
        }

        for (int j = 1; j <= n; j++) {
            for (int k = j + 1; k <= n; k++) {
                if (conn[i][j] && conn[i][k] && conn[j][k]) {
                    ans += (tot - cnt[j] - cnt[k] + 1);
                }
            }
        }
    }
    cout << ans/2;

}