#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int n, m;
char G[202][202];
int dist[202][202];
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> G[i][j];
        }
    }

    memset(dist, -1, sizeof(dist));
    dist[0][0] = 0;
    queue<pair<int, int>> q;
    q.push(mp(0, 0));
    while (!q.empty()) {
        auto [a, b] = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int na = a + dx[i];
            int nb = b + dy[i];
            if (inGrid(na, nb) && G[na][nb] == '.' && dist[na][nb] == -1) {
                dist[na][nb] = dist[a][b] + 1;
                q.push(mp(na, nb));
            }
        }
    }

    vector<pair<int, int>> route;
    int cx = n - 1, cy = m - 1;
    while (cx + cy) {
        route.push_back(mp(cx, cy));
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (inGrid(nx, ny) && dist[nx][ny] + 1 == dist[cx][cy]) {
                cx = nx;
                cy = ny;
                break;
            }
        }
    }
    route.push_back(mp(0, 0));
    reverse(all(route));

    for (auto& [a, b] : route) cout << a + 1 << ' ' << b + 1 << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}