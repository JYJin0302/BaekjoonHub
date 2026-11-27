#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


int n, m;
int G[101][101];
bool vis[11][101][101];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
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
    int x;
    cin >> x;

    if (G[n - 1][m - 1] != G[0][0]) {
        cout << "DEAD\n";
        return;
    }

    vis[0][0][0] = 1;
    queue<pair<int, pair<int, int>>> q;
    q.push(mp(0, mp(0, 0)));
    while (!q.empty()) {
        auto [d, v] = q.front(); q.pop();
        auto [a, b] = v;

        if (G[a][b] == G[0][0]) {
            d = x;
            if (vis[d][a][b]) continue;
            vis[d][a][b] = 1;
        }
        else if (d == 0) continue;

        if (a == n - 1 && b == m - 1) {
            cout << "ALIVE\n";
            return;
        }

        for (int i = 0; i < 4; i++) {
            int na = a + dx[i];
            int nb = b + dy[i];
            if (inGrid(na, nb) && !vis[d - 1][na][nb]) {
                vis[d - 1][na][nb] = 1;
                q.push(mp(d - 1, mp(na, nb)));
            }
        }
    }
    cout << "DEAD\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
   // cin >> t;
    while (t--) solve();
}