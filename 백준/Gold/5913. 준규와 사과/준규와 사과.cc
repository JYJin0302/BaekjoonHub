#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

bool vis[5][5];
int dx[] = { -1, 0, 1 , 0 };
int dy[] = { 0, 1, 0, -1 };
bool inGrid(int x, int y) {
    return x >= 0 && x < 5 && y >= 0 && y < 5;
}

map<int, int> U[5][5], D[5][5];

void track(int x, int y, int cnt) {


    vis[x][y] = 1;
    if (cnt == 0) {
        int ss = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (vis[i][j]) {
                    ss += (1 << (i * 5 + j));
                }
            }
        }

        U[x][y][ss]++;
        vis[x][y] = 0;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (inGrid(nx, ny) && !vis[nx][ny]) {
            track(nx, ny, cnt - 1);
        }
    }
    vis[x][y] = 0;
}

void solve() {

    int n;
    cin >> n;

    int base = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        vis[a][b] = 1;
        base += (1 << (a * 5 + b));
    }

    track(0, 0, (25 - n) / 2);
    swap(U, D);
    track(4, 4, (25 - n) / 2);

    int ans = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            for (auto [f, v] : U[i][j]) {                
                int t = (1 << 25) - 1 - f + base + (1 << (i*5 + j));
                ans += v * D[i][j][t];
            }
        }
    }
    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}