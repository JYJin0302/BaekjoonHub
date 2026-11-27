#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int n, m, k;
bool vis[1010][1010];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
bool inGrid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void solve() {
    cin >> n >> m >> k;
    if (k > n * m) {
        cout << 0;
        return;
    }

    int cx = 1, cy = 1, dir = 0;
    k--;
    vis[1][1] = 1;
    while (k--) {
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];

        if (!inGrid(nx, ny) || vis[nx][ny]) {
            dir = (dir + 1) % 4;
            nx = cx + dx[dir];
            ny = cy + dy[dir];
        }

        cx = nx;
        cy = ny;
        vis[cx][cy] = 1;
    }

    cout << cx << ' ' << cy << '\n';
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}