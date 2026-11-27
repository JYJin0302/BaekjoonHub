#include <bits/stdc++.h>
using namespace std;

int n, m;
string tmp[25];
string inp[25];

int dp[25][25][25][25];

bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}

int solve(int x1, int y1, int x2, int y2) {

    if (x1 > x2 || y1 > y2) return 0;
    if (dp[x1][y1][x2][y2] != -1) return dp[x1][y1][x2][y2];

    map<int, bool> cnt;
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {

            if (tmp[i][j] == '.') {}
            else if (tmp[i][j] == 'B') {
                // horizontal
                int tx = solve(x1, y1, i - 1, y2) ^ solve(i + 1, y1, x2, y2);
                cnt[tx] = 1;
            }
            else if (tmp[i][j] == 'R') {
                // vertical
                int tx = solve(x1, y1, x2, j - 1) ^ solve(x1, j + 1, x2, y2);
                cnt[tx] = 1;
            }
            else if (tmp[i][j] == 'G') {
                int tx = solve(x1, y1, i - 1, j - 1);
                tx ^= solve(x1, j + 1, i - 1, y2);
                tx ^= solve(i + 1, y1, x2, j - 1);
                tx ^= solve(i + 1, j + 1, x2, y2);
                cnt[tx] = 1;
            }

        }
    }

    int res = 0;
    while (cnt[res])res++;
    return dp[x1][y1][x2][y2] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < 25; i++) {
        inp[i] = string(25, '.');
        tmp[i] = string(25, '.');
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> inp[i][j];
        }
    }
    
    int ix = 0, iy = 0;
    int vx = 12, vy = 0;
    for (int i = 0; i < 25; i++) {
        if (inGrid(ix, iy)) tmp[vx][vy] = inp[ix][iy];

        int tx = ix, ty = iy, cnt = 0;
        while (cnt < 25) {
            tx--, ty++;
            cnt++;
            if (inGrid(tx, ty)) {
                tmp[vx - cnt][vy] = inp[tx][ty];
            }
        }
        tx = ix, ty = iy, cnt = 0;
        while (cnt < 25) {
            tx++, ty--;
             cnt++;
            if (inGrid(tx, ty)) {
                tmp[vx+cnt][vy] = inp[tx][ty];
            }
        }
        vy++;
        ix++, iy++;
    }

    //cout << "VER1\n";
    //for (auto i : tmp) cout << i << '\n';

    memset(dp, -1, sizeof(dp));
    int v1 = solve(0, 0, 24, 24);


    for (int i = 0; i < 25; i++) tmp[i] = string(25, '.');

    ix = 1, iy = 0;
    vx = 12, vy = 0;
    for (int i = 0; i < 25; i++) {
        if (inGrid(ix, iy)) tmp[vx][vy] = inp[ix][iy];

        int tx = ix, ty = iy, cnt = 0;
        while (cnt < 25) {
            tx--, ty++;
            cnt++;
            if (inGrid(tx, ty)) {
                tmp[vx - cnt][vy] = inp[tx][ty];
            }
        }
        tx = ix, ty = iy, cnt = 0;
        while (cnt < 25) {
            tx++, ty--;
            cnt++;
            if (inGrid(tx, ty)) {
                tmp[vx + cnt][vy] = inp[tx][ty];
            }
        }
        vy++;
        ix++, iy++;
    }

   // cout << "VER2\n";
    //for (auto i : tmp) cout << i << '\n';

    memset(dp, -1, sizeof(dp));
    int v2 = solve(0, 0, 24, 24);

    v1 ^= v2;

    if (v1 == 0) cout << 'L';
    else cout << 'W';
}