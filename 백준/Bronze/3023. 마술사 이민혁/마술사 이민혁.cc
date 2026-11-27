#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

char G[101][101];

void solve() {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> G[i][j];

            G[2 * n - 1 - i][j] = G[i][2 * m - 1 - j] = G[2 * n - 1 - i][2 * m - 1 - j] = G[i][j];
        }
    }

    int x, y;
    cin >> x >> y;
    x--, y--;
    G[x][y] = char('.' + '#' - G[x][y]);

    for (int i = 0; i < n * 2; i++) {
        for (int j = 0; j < m * 2; j++) {
            cout << G[i][j];
        }
        cout << '\n';
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}