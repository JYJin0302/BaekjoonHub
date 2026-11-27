#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, m;
int dx[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int dy[] = { -1, 1, 2, 2, 1, -1, -2, -2 };
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}



int G[55][55];
ll dp[55][55];
int cnt[55][55];
bool vis[33][33];

vector<pair<int, int>> nxt(int a, int b) {
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int>> q;
    vector<pair<int, int>> res;
    q.push(mp(a, b));
    while (!q.empty()) {

        auto [x, y] = q.front(); q.pop();

        for (int i = 0; i < 8; i++) {
            int na = x + dx[i];
            int nb = y + dy[i];

            if (!inGrid(na, nb) || G[na][nb] == 2 || vis[na][nb]) continue;
            vis[na][nb] = 1;
            if (G[na][nb] == 1) q.push(mp(na, nb));
            else if (G[na][nb] == 0) res.push_back(mp(na, nb));
        }
    }
    return res;
}

void solve() {

    cin >> n >> m;

    int sx, sy;
    int ex, ey;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> G[i][j];
            if (G[i][j] == 3) {
                tie(sx, sy) = mp(i, j);
                G[i][j] = 1;
                G[i][j] = 0;
            }
            if (G[i][j] == 4) {
                tie(ex, ey) = mp(i, j);
                G[i][j] = 0;
            }
        }
    }

    memset(dp, -1, sizeof(dp));
    dp[sx][sy] = 1;
    queue<pair<int, int>> q;
    q.push(mp(sx, sy));
    while (!q.empty()) {

        auto [a, b] = q.front();
        q.pop();

        if (mp(a, b) == mp(ex, ey)) {
            cout << cnt[a][b] - 1 << '\n' << dp[a][b] << '\n';
            return;
        }
        for (auto [na, nb] : nxt(a, b)) {
            if (dp[na][nb] == -1) {
                cnt[na][nb] = cnt[a][b] + 1;
                dp[na][nb] = dp[a][b];
                q.push(mp(na, nb));
            }
            else if (cnt[na][nb] == cnt[a][b] + 1) {
                dp[na][nb] += dp[a][b];
            }
        }

    }
    cout << -1;



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}