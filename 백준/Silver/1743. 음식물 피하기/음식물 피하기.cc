#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, k;
int A[101][101];
bool v[101][101];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool inGrid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

int bfs(int a, int b) {

    v[a][b] = 1;
    queue<pair<int, int>> q;
    q.push({ a, b });

    int res = 0;
    while (!q.empty()) {

        int x, y;
        tie(x, y) = q.front();
        q.pop();
        res++;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (inGrid(nx, ny) && A[nx][ny] == 1 && !v[nx][ny]) {
                v[nx][ny] = 1;
                q.push({ nx, ny });

            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    cin >> n >> m >> k;

    while (k--) {

        int a, b;
        cin >> a >> b;

        A[a][b] = 1;
    }

    int ans = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (v[i][j] || A[i][j] == 0) continue;

            int cnt = bfs(i, j);
            ans = max(ans, cnt);
        }
    }

    cout << ans;
}