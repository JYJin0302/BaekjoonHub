#include <bits/stdc++.h>
using namespace std;

int n, m, ans, r, c, nr, nc;
int grid[100][100];
int check[100][100];
queue<pair<int, int>> q;
queue<pair<int, int>> temp;
int step[4][2] = { {1, 0}, {-1, 0}, {0, -1}, {0, 1} };


bool ingrid(int r, int c) {
    return (r >= 0 && r < n) && (c >= 0 && c < m);
}

void bfs() {
    while (!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        if (r == n - 1 && c == m - 1) return;
        for (int i = 0; i < 4; i++) {
            nr = r + step[i][0];
            nc = c + step[i][1];
            if (ingrid(nr, nc) && !check[nr][nc] && grid[nr][nc]) {
                check[nr][nc] = 1;
                temp.push(make_pair(nr, nc));
            }
        }
    }
    swap(q, temp);
    ans++;
    bfs();
}

int main() {
    cin >> n >> m;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '1') grid[i][j] = 1;
        }
    }
    q.push(make_pair(0, 0));
    bfs();
    cout << ans + 1;
}