#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
queue<pair<int, int>> q;
vector<vector<int>> grid(1000, vector<int>(1000));
int step[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
queue<pair<int, int>> temp;

bool ingrid(int r, int c) {
    return (r >= 0 && r < n) && (c >= 0 && c < m);
}

void bfs() {
    while (!q.empty()) {
        int cur_r = q.front().first;
        int cur_c = q.front().second;
        grid[cur_r][cur_c] = 1;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newr = cur_r + step[i][0];
            int newc = cur_c + step[i][1];
            if (ingrid(newr, newc) && grid[newr][newc] == 0) {
                grid[newr][newc] = 1;
                temp.push(make_pair(newr, newc));
            }
        }
    }
    swap(q, temp);
    if (q.empty()) return;
    ans++;
    bfs();
}


int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
        if (grid[i][j] == 1) q.push(make_pair(i, j));
    }
    ans = 0;
    bfs();
    bool ok = true;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (grid[i][j] == 0) ok = false;
    }
    if (!ok) cout << -1;
    else cout << ans;

}