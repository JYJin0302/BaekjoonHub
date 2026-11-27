#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };
int grid[2001][2001];

bool inGrid(int x, int y) {
    return x > 0 && x <= n && y > 0 && y <= n;
}

vector<int> root;
int find(int n) {
    if (root[n] == n) return n;

    return root[n] = find(root[n]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;

    vector<pair<int, int>> A(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        A[i] = { a, b };
        grid[a][b] = i + 1;
    }

    queue<tuple<int, int>> tq; // civ, year, x, y
    queue<tuple<int, int>> ttq;

    for (auto i : A) tq.push(i);

    root = vector<int>(m + 1);
    for (int i = 1; i <= m; i++) root[i] = i;

    int ans = 0;
    int connect = 0;
    while (connect != m - 1) {
        while (!tq.empty()) {

            int c, d;
            tie(c,d) = tq.front();
            ttq.push({ c,d });
            tq.pop();

            for (int i = 0; i < 4; i++) {
                int nc = c + dx[i];
                int nd = d + dy[i];

                if (inGrid(nc, nd) && grid[nc][nd] != grid[c][d] && grid[nc][nd] != 0) {
                    int na = grid[nc][nd];
                    int a = grid[c][d];

                    find(na), find(a);

                    if (root[na] != root[a]) {
                        
                        connect++;
                        root[root[na]] = root[a];
                    }
                }
            }
        }

        if (connect == m - 1) break;
        while (!ttq.empty()) {
            
            int c, d;
            tie(c, d) = ttq.front();
            ttq.pop();

            for (int i = 0; i < 4; i++) {
                int nc = c + dx[i];
                int nd = d + dy[i];

                if (inGrid(nc, nd) && grid[nc][nd] == 0) {

                    grid[nc][nd] = grid[c][d];
                    tq.push({nc, nd});
                }
            }
        }
        ans++;
    }

    cout << ans;
}