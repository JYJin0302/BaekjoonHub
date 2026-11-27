#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define all(x) x.begin(), x.end()

int A[55][55];
bool vs[55][55];

int n, m;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1,0 ,-1 };

bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}

int ans = 0;
int go(int x, int y, int dir, int p) {
    int val = A[x][y];
    if (p == 0) return val;

    int res = 0;
    for (int j = 0; j < 4; j++) {
        if (abs(j - dir) == 2) continue;
        int nx = x + dx[j];
        int ny = y + dy[j];

        int c = 1;
        if (j != dir) c = 2;

        if (p < c || !inGrid(nx, ny)) continue;
        if (!vs[nx][ny]) {
            vs[nx][ny] = 1;

            res = max(res, go(nx, ny, j, p - c));
            vs[nx][ny] = 0;
        }
    }
    return res + val;
}

void solve() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> A[i][j];
    }

    int x, y, p;
    cin >> x >> y >> p;

    vs[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        ans = max(ans, go(x, y, i, p));
    }
    cout << ans;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
