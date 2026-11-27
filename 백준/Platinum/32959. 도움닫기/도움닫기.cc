#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, m;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool inGrid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
char G[2020][2020];
bool vis[2020][2020];
int D[4][2020][2020];

void setArr() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            vis[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (G[i][j] == '#') D[2][i][j] = 0, D[1][i][j] = 0;
            else {
                D[2][i][j] = 1 + (i > 1 ? D[2][i - 1][j] : 0);
                D[1][i][j] = 1 + (j > 1 ? D[1][i][j - 1] : 0);
            }
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = m;j >= 1; j--){
            if (G[i][j] == '#') D[0][i][j] = 0, D[3][i][j] = 0;
            else {
                D[0][i][j] = 1 + (i + 1 <= n ? D[0][i + 1][j] : 0);
                D[3][i][j] = 1 + (j + 1 <= m ? D[3][i][j + 1] : 0);
            }
        }
    }

}

void solve() {
    
    cin >> n >> m;

    int sx, sy, ex, ey;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> G[i][j];
            if (G[i][j] == 'S') sx = i, sy = j;
            if (G[i][j] == 'E') ex = i, ey = j;
        }
    }

    setArr();

    queue<pair<int, int>> q;
    q.push(mp(sx, sy));
    vis[sx][sy] = 1;

    while (!q.empty()) {
        auto [a, b] = q.front(); q.pop();
       //cout << "Cur: " << a << ' ' << b << '\n';

        for (int i = 0; i < 4; i++) {
            int na = a + dx[i];
            int nb = b + dy[i];

            if (!inGrid(na, nb) || vis[na][nb]) continue;

            if (G[na][nb] == '#') {
                int d = D[i][a][b];
                //cout << "Go jump: " << d << " | " << i << ' ' << a << ' ' << b << '\n';
                while (d && inGrid(na, nb)) {
                    if (!vis[na][nb] && G[na][nb] != '#') {
                        vis[na][nb] = 1;
                        q.push(mp(na, nb));
                    }

                    d--;
                    na += dx[i];
                    nb += dy[i];
                }

            }
            else {
                vis[na][nb] = 1;
                q.push(mp(na, nb));
            }

        }

    }

    if (vis[ex][ey]) cout << "YES\n";
    else cout << "NO\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}