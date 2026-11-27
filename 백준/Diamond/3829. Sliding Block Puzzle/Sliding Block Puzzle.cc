#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, m;
char G[55][55];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
const ll INF = 0x3f3f3f3f3f3f3f3f;
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m && G[x][y] != '*';
}
bool inGrid(pair<int, int> p) {
    return inGrid(p.x, p.y);
}
bool chkB(int x, int y) {
    for (int dx = 0; dx < 2; dx++) {
        for (int dy = 0; dy < 2; dy++) {
            if (!inGrid(x + dx, y + dy) || G[x + dx][y + dy] != '.') return 0;
        }
    }
    return 1;
}

ll dp[4][55][55];
// 비어있는 방향
ll d1[55][55], d2[55][55];
void update(int x, int y, int bx, int by, ll dist[][55]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j] = -1;
        }
    }

    for (int dx = 0; dx < 2; dx++) {
        for (int dy = 0; dy < 2; dy++) dist[bx + dx][by + dy] = INF;
    }
    queue<pair<int, int>> q;
    dist[x][y] = 0;
    q.push(mp(x, y));
    while (!q.empty()) {
        auto [a, b] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int na = a + dx[i];
            int nb = b + dy[i];
            if (inGrid(na, nb) && dist[na][nb] == -1) {
                dist[na][nb] = dist[a][b] + 1;
                q.push(mp(na, nb));
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[i][j] == -1) dist[i][j] = INF;
        }
    }
}

int dx8[] = { -2, -2, -1, 0, 1, 1, 0, -1 };
int dy8[] = { -1, 0, 1, 1, 0, -1, -2, -2 };

int dx2[] = { -1, -1, 0, 1, 2, 2, 1, 0 };
int dy2[] = { 0, 1, 2, 2, 1, 0, -1, -1 };

void solve() {

    int sx = -1, sy = -1;
    vector<pair<int, int>> init;

    //cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> G[i][j];
            if (G[i][j] == 'X' && sx == -1) {
                sx = i, sy = j;
            }
            if (G[i][j] == '.') init.push_back(mp(i, j));
        }
    }

    if (sx == 0 && sy == 0) {
        cout << 0 << '\n';
        return;
    }

    // initialize
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (G[i][j] != '*') G[i][j] = '.';
            for (int d = 0; d < 4; d++) {
                dp[d][i][j] = -1;
            }
        }
    }

    priority_queue<pair<ll, pair<int, pair<int, int>>>> pq;
    update(init[0].x, init[0].y, sx, sy, d1);
    update(init[1].x, init[1].y, sx, sy, d2);
    // 값, 방향, 위치
    for (int i = 0; i < 4; i++) {
        pair<int, int> p1 = mp(sx + dx2[i << 1], sy + dy2[i << 1]);
        pair<int, int> p2 = mp(sx + dx2[i << 1 | 1], sy + dy2[i << 1 | 1]);
        if (!inGrid(p1) || !inGrid(p2)) continue;
        
        ll cst = min(d1[p1.x][p1.y] + d2[p2.x][p2.y], d2[p1.x][p1.y] + d1[p2.x][p2.y]);
        //cout << "Chk: " << p1.x << ' ' << p1.y << " + " << p2.x << ' ' << p2.y << " | " << cst << '\n';
        if (cst < INF) {
            pq.push(mp(-cst, mp(i, mp(sx, sy))));
        }
    }

    while (!pq.empty()) {

        ll v = pq.top().x;
        int dir = pq.top().y.x;
        auto [a, b] = pq.top().y.y;
        pq.pop();

        if (dp[dir][a][b] != -1) continue;
        dp[dir][a][b] = -v;

        // cout << "Go: " << -v << " | " << dir << ' ' << a << ' ' << b << '\n';

        if (a == 0 && b == 0) {
            cout << -v << '\n';
            return;
        }

        int na = a + dx[dir], nb = b + dy[dir];
        if (inGrid(na, nb) && dp[(dir + 2) % 4][na][nb] == -1) {
            pq.push(mp(v - 1, mp((dir + 2) % 4, mp(na, nb))));
        }

        pair<int, int> p1 = mp(a + dx2[dir << 1], b + dy2[dir << 1]);
        pair<int, int> p2 = mp(a + dx2[dir << 1 | 1], b + dy2[dir << 1 | 1]);
        assert(inGrid(p1) && inGrid(p2));
        update(p1.x, p1.y, a, b, d1);
        update(p2.x, p2.y, a, b, d2);
        for (int nd = 0; nd < 4; nd++) {
            if (nd == dir || dp[nd][a][b] != -1) continue;

            pair<int, int> np1 = mp(a + dx2[nd << 1], b + dy2[nd << 1]);
            pair<int, int> np2 = mp(a + dx2[nd << 1 | 1], b + dy2[nd << 1 | 1]);
            if (!inGrid(np1) || !inGrid(np2)) continue;

            ll cst = min(d1[np1.x][np1.y] + d2[np2.x][np2.y], d2[np1.x][np1.y] + d1[np2.x][np2.y]);
            if (cst < INF) {
                pq.push(mp(v - cst, mp(nd, mp(a, b))));
            }
        }

    }
    cout << -1 << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        solve();
    }
}
