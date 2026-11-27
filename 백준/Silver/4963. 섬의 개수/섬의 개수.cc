#include <bits/stdc++.h>
using namespace std;

int n, m;
int grid[50][50];
int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy[] = { 1, 1, 1, 0, -1, -1, -1, 0 };

bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}

void bfs(int x, int y) {

    grid[x][y] = 0;

    queue<pair<int, int>> q;
    q.push({ x, y });
    while (!q.empty()) {

        int a, b;
        tie(a, b) = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int na = a + dx[i];
            int nb = b + dy[i];
            if (inGrid(na, nb) && grid[na][nb] == 1) {
                grid[na][nb] = 0;
                q.push({ na, nb });
            }
        }
    }
}

int main() {


    cin >> m >> n;

    while (!(n == 0 && m == 0)) {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }


        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    cnt++;
                    bfs(i, j);
                }
            }
        }

        cout << cnt << '\n';

        cin >> m >> n;
    }
}