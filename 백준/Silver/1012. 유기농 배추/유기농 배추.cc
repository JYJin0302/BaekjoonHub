#include <bits/stdc++.h>
using namespace std;
int t, n, m, k, n1, n2, r, c, nr, nc, ans;
vector<vector<int>> grid;
vector<vector<int>> check;
queue<pair<int, int>> q;

int step[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

bool ingrid(int r, int c) {
    return (r >= 0 && r < n) && (c >= 0 && c < m);
}

void bfs() {
    while (!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            nr = r + step[i][0];
            nc = c + step[i][1];
            if (ingrid(nr, nc) && !check[nr][nc] && grid[nr][nc]) {
                check[nr][nc] = 1;
                q.push(make_pair(nr, nc));
            }
        }
    }
}

int main() {
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n >> m >> k;
        grid = vector<vector<int>>(n, vector<int>(m));
        check = vector<vector<int>>(n, vector<int>(m));
        while (k--) {
            cin >> n1 >> n2;
            grid[n1][n2] = 1;
        }
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (grid[i][j] && !check[i][j]) {
                q.push(make_pair(i, j));
                bfs();
                ans++;
            }
        }
        cout << ans << endl;
    }
}