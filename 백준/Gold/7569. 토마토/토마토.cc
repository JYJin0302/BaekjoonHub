#include <bits/stdc++.h>
using namespace std;

int grid[101][101][101];
int n, m, h, x, y, z, nx, ny, nz;
queue<tuple<int, int, int>> q;
queue<tuple<int, int, int>> temp;
int step[6][3] = { {-1, 0, 0}, {1, 0, 0}, {0, -1, 0}, {0, 1, 0}, {0, 0, -1}, {0, 0, 1} };
int ans;

bool ingrid(int z, int x, int y) {
    return (z >= 0 && z < h) && (x >= 0 && x < n) && (y >= 0 && y < m);
}

void bfs() {
    while (!q.empty()) {
        tie(z, x, y) = q.front();
        q.pop();
        for (int i = 0; i < 6; i++) {
            nz = z + step[i][0];
            nx = x + step[i][1];
            ny = y + step[i][2];
            if (ingrid(nz, nx, ny) && grid[nz][nx][ny] == 0) {
                grid[nz][nx][ny] = 1;
                temp.push(make_tuple(nz, nx, ny));
            }
        }
    }

    swap(q, temp);
    if (q.empty()) return;
    ans++;
    bfs();
}


int main() {
    cin >> m >> n >> h;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                cin >> grid[i][j][k];
                if (grid[i][j][k] == 1) q.push(make_tuple(i, j, k));
            }
        }
    }

    ans = 0;
    bfs();

    bool ok = true;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n; j++) {
           for (int k = 0; k < m; k++) {
               if (grid[i][j][k] == 0) {
                   ok = false; break;
               }
            }
           if (!ok) break;

        }
        if (!ok) break;
    }

    if (!ok) cout << -1;
    else cout << ans;

}