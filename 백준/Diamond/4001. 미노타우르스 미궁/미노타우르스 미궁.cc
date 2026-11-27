#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int n, m;
char grid[2020][2020];
int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };


bool inGrid(int x, int y) {
    return x >= 0 && x <= n + 1 && y >= 0 && y <= m + 1;
}

int U[2020][2020], D[2020][2020], B[2020][2020];

int getSum(int x1, int y1, int x2, int y2, int a[][2020]) {
    int res = a[x2][y2];
    if (x1) res -= a[x1 - 1][y2];
    if (y1) res -= a[x2][y1 - 1];
    if (x1 && y1) res += a[x1 - 1][y1 - 1];
    return res;
}

void solve() {

    memset(grid, '#', sizeof(grid));

    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i + 1][j + 1];
            if (grid[i + 1][j + 1] == '#') B[i + 1][j + 1] = 1;
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            grid[i][j] = '.';
            grid[n + 1 - i][m + 1 - j] = '.';
        }
    }

    queue<pair<int, int>> q;
    q.push(mp(0, 2));
    U[0][2] = 1;
    while (!q.empty()) {
        auto [a, b] = q.front(); q.pop();
        for (int i = 0; i < 8; i++) {
            int na = a + dx[i];
            int nb = b + dy[i];

            if (inGrid(na, nb) && grid[na][nb] == '#' && U[na][nb] == 0) {
                U[na][nb] = 1;
                q.push(mp(na, nb));
            }
        }
    }

    q.push(mp(2, 0));
    D[2][0] = 1;
    while (!q.empty()) {
        auto [a, b] = q.front(); q.pop();
        for (int i = 0; i < 8; i++) {
            int na = a + dx[i];
            int nb = b + dy[i];

            if (inGrid(na, nb) && grid[na][nb] == '#' && D[na][nb] == 0) {
                D[na][nb] = 1;
                q.push(mp(na, nb));
            }
        }
    }

    /*for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            if (U[i][j]) cout << 'U';
            else if (D[i][j]) cout << 'D';
            else cout << grid[i][j];
        }
        cout << '\n';
    }*/

    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            if (j) U[i][j] += U[i][j - 1], D[i][j] += D[i][j - 1], B[i][j] += B[i][j - 1];
            if (i) U[i][j] += U[i - 1][j], D[i][j] += D[i - 1][j], B[i][j] += B[i - 1][j];
            if (i && j) U[i][j] -= U[i - 1][j - 1], D[i][j] -= D[i - 1][j - 1], B[i][j] -= B[i - 1][j - 1];
        }
    }

    int ans = 2000, ansx = -1, ansy = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i + j == 2 || i + j == n + m || grid[i][j] == '#') continue;

            // left upper : (i, j)
            int l = 0, r = min(m - j, n - i), res = 2020;
            if (n-i == m-j) r--;
            while (l <= r) {

                int md = (l + r) >> 1;

                int sB = getSum(i, j, i + md, j + md, B);
                if (sB > 0) {
                    r = md - 1;
                    continue;
                }

                int sU = getSum(i - 1, j - 1, i + md + 1, j + md + 1, U);
                int sD = getSum(i - 1, j - 1, i + md + 1, j + md + 1, D);

                
                if (sU && sD) {
                    res = md;
                    r = md - 1;
                }
                else {
                    l = md + 1;
                }
            }

            if (res < ans) {
                ans = res;
                ansx = i, ansy = j;
            }

        }
    }

    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (ansG[i][j] == -1) cout << grid[i][j];
            else cout << ansG[i][j];
        }
        cout << '\n';
    }*/

    if (ans == 2000) cout << "Impossible\n";
    else cout << ans + 1 << ' ' << ansy << ' ' << ansx;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}