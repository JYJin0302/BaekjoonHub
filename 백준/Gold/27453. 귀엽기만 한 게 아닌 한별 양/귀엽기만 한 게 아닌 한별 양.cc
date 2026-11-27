#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair

int n, m, k;
int G[1010][1010];
int dist[4][4][1010][1010];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}



void solve() {
    cin >> n >> m >> k;

    int sx, sy, ex, ey;
    sx = sy = ex = ey = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (isdigit(c)) {
                G[i][j] = c - '0';
            }
            else {
                if (c == 'S') {
                    sx = i, sy = j;
                }
                else if (c == 'H') {
                    ex = i, ey = j;
                }
                else {
                    G[i][j] = 100;
                }
            }
        }
    }

    memset(dist, -1, sizeof dist);
    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (j != (i + 2) % 4) {
                dist[i][j][sx][sy] = 0;
                q.push(mp(i * 4 + j, mp(sx, sy)));
            }
        }
    }
    while (!q.empty()) {

        int d = q.front().x;
        int tx = d / 4, ty = d % 4;
        auto [a, b] = q.front().y;
        q.pop();

        if (a == ex && b == ey) {
            cout << dist[tx][ty][a][b] << '\n';
            return;
        }

        for (int i = 0; i < 4; i++) {
            if (i == (tx + 2) % 4) continue;
            int na = a + dx[i];
            int nb = b + dy[i];
            if (!inGrid(na, nb) || G[na][nb] == 100) continue;

            int newC = G[na][nb] + G[a][b];
            if (dist[tx][ty][a][b]) {
                int td = (tx + 2) % 4;
                int ta = a + dx[td];
                int tb = b + dy[td];
                newC += G[ta][tb];
            }

            if (newC > k || dist[i][tx][na][nb] != -1) continue;
            dist[i][tx][na][nb] = dist[tx][ty][a][b] + 1;
            q.push(mp(i * 4 + tx, mp(na, nb)));
        }
    }

    cout << -1 << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}