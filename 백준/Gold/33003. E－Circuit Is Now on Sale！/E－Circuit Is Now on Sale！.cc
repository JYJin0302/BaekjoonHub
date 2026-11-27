#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, m;
char G[55][55];
int dx[] = { -1, 0, 1,  0 };
int dy[] = { 0, 1, 0, -1 };
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}

bool vis[55][55];


ll cal(int x, int y) {
    
    vis[x][y] = 1;
    if (isdigit(G[x][y])) {
        return G[x][y] - '0';
    }

    vector<ll> res;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (inGrid(nx, ny) && !vis[nx][ny] && G[nx][ny] != '.') {
            res.push_back(cal(nx, ny));
        }
    }
    sort(all(res));

    if (G[x][y] == '+') return res[0] + res[1];
    if (G[x][y] == '-') return res[1] - res[0];
    if (G[x][y] == '*') return res[0] * res[1];
    if (G[x][y] == '/') return res[1] / res[0];
    return res[0];
}

void solve() {

    cin >> n >> m;

    int sx, sy;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> G[i][j];
            if (G[i][j] == 'P') {
                sx = i, sy = j;
            }
        }
    }

    cout << cal(sx, sy);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}