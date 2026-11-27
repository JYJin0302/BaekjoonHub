#include <bits/stdc++.h>
using namespace std;


int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
bool check[1001][1001][12][2];
int n, m, k;
vector<string> grid;

bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        grid.push_back(s);
    }

    queue<tuple<int, int, int, int>> pq;  // day, breakcnt, x, y
    pq.push({ -1, 0, 0, 0 });
    check[0][0][0][0] = 1;
    while (!pq.empty()) {

        int a, b, c, d;
        tie(a, d, b, c) = pq.front();
        pq.pop();
        a *= -1;
        d *= -1;

        if (b == n - 1 && c == m - 1) {
            cout << a;
            return 0;
        }

        if (!check[b][c][d][a % 2]) {
            check[b][c][d][a % 2] = 1;
            pq.push({ -a - 1,-d, b, c });
        }

        for (int i = 0; i < 4; i++) {
            int nb = b + dx[i];
            int nc = c + dy[i];
            if (inGrid(nb, nc)) {
                if (a % 2 == 1 && !check[nb][nc][d + (grid[nb][nc] == '1')][1] && (grid[nb][nc] == '0' || d < k)) {
                    check[nb][nc][d + (grid[nb][nc] == '1')][1] = 1;
                    pq.push({ -a - 1, -d - (grid[nb][nc] == '1'), nb, nc });
                }
                else if (a % 2 == 0 && !check[nb][nc][d][0] && grid[nb][nc] == '0') {
                    check[nb][nc][d][0] = 1;
                    pq.push({ -a - 1, -d , nb, nc });
                }
            }
        }
    }

    cout << -1;
}