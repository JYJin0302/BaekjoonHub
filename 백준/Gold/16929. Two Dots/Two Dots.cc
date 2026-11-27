#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<bool>> check;
bool ok;

bool inGrid(int x, int y) {
    return (x >= 0 && x < n&& y >= 0 && y < m);
}
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

void dfs(int x, int y, char c, int px = -1, int py = -1) {

    int nx, ny;
    for (int i = 0; i < 4; i++) {
        nx = x + dx[i];
        ny = y + dy[i];
        if (inGrid(nx, ny) && grid[nx][ny] == c && !(nx == px && ny == py)) {
            if (check[nx][ny] == 1) {
                 ok = true;
                 return;
            }
            check[nx][ny] = 1;
            dfs(nx, ny, c, x, y);
        }
    }
}


int main() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        grid.push_back(s);
    }

    check = vector<vector<bool>>(n, vector<bool>(m));

    ok = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!check[i][j]) {
                check[i][j] = 1;
                dfs(i, j, grid[i][j]);
                if (ok) {
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }

    cout << "No";
}