#include <bits/stdc++.h>
using namespace std;

int n, h, m;

int grid[11][31]; // grid[i][j]: i, j에서 다음 세로선 위치
bool ans_found = 0;

void runcase() {
    bool ok = 1;

    for (int i = 1; i <= n; i++) {

        int curr = i, height = 1;
        while (height <= h) {
            curr = grid[curr][height];
            height++;
        }

        if (curr != i) ok = 0;
    }

    if (ok) ans_found = 1;
}

void select(int target, int cnt = 0, int pi = 0, int pj = 0) {
    if (cnt == target) {
        runcase();
        return;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= h; j++) {
            if (i < pi || (i == pi && j <= pj)) continue;
            if (grid[i][j] == i && grid[i + 1][j] == i + 1) {
                grid[i][j] = i + 1;
                grid[i + 1][j] = i;

                select(target, cnt + 1, i, j);

                grid[i][j] = i;
                grid[i + 1][j] = i + 1;
            }
        }
    }
}

int main() {

    cin >> n >> m >> h;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= h; j++) {
            grid[i][j] = i;
        }
    }
    

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        grid[b][a] = b + 1;
        grid[b + 1][a] = b;
    }

    int ans = 0;
    while (ans <= 3) {
        select(ans);

        if (ans_found) break;
        ans++;
    }

    if (ans == 4) ans = -1;

    cout << ans;
}