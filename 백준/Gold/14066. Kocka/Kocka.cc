#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int G[55][55];
char ans[1010][1010];

string block[] = {
    "..+---+",
    "./   /|",
    "+---+ |",
    "|   | +",
    "|   |/.",
    "+---+.."
};

int xl, xr, yl, yr;

void build(int x, int y) {
    x -= 2;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            if (block[i][j] == '.') continue;
            ans[x + i][y + j] = block[i][j];

            xl = min(xl, x + i);
            xr = max(xr, x + i);
            yl = min(yl, y + j);
            yr = max(yr, y + j);
        }
    }
}

void solve() {

    memset(ans, '.', sizeof ans);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> G[i][j];
    }

    xl = yl = 2000;
    xr = yr = -1;
    int bx = 500, by = 500;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < G[i][j]; k++) {
                int nx = bx + 2 * i - 3 * k;
                int ny = by - 2 * i + 4 * j;
                build(nx, ny);
            }
        }
    }

    for (int i = xl; i <= xr; i++) {
        for (int j = yl; j <= yr; j++) {
            cout << ans[i][j];
        }cout << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}