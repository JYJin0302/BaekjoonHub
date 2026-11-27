#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int n, m;
bool grid[5050][5050];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0 ,1, 0, -1 };

bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}

void solve() {
    cin >> n >> m;
    int x = 0, y = 0;

    int cnt = n * m-1;
    int dir = 0;
    while (cnt--) {
        grid[x][y] = 1;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (!inGrid(nx, ny) || grid[nx][ny]) {
            dir = (dir + 1) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }
        x = nx, y = ny;
    }
    cout << x << ' ' << y;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}