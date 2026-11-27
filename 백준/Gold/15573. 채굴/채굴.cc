#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int n, m, k;
int G[1010][1010];
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}

bool chk[1010][1010];
void solve() {

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> G[i][j];
        }
    }


    int l = 1, r = 1e6, ans = r;
    while (l <= r) {
        int md = (l + r) >> 1;

        memset(chk, 0, sizeof(chk));

        int cnt = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (auto f : { 0, m - 1 }) {
                if (G[i][f] <= md && !chk[i][f]) {
                    chk[i][f] = 1;
                    q.push(mp(i, f));
                }
            }
        }
        for (int j = 1; j < m - 1; j++) {
            if (G[0][j] <= md && !chk[0][j]) {
                chk[0][j] = 1;
                q.push(mp(0, j));
            }
        }

        while (!q.empty()) {
            auto [a, b] = q.front(); q.pop();
            cnt++;

            for (int i = 0; i < 4; i++) {
                int na = a + dx[i];
                int nb = b + dy[i];

                if (inGrid(na, nb) && !chk[na][nb] && G[na][nb] <= md) {
                    chk[na][nb] = 1;
                    q.push(mp(na, nb));
                }
            }
        }

        if (cnt >= k) {
            ans = md;
            r = md - 1;
        }
        else l = md + 1;
    }

    cout << ans;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}