#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

char ans[505][505];

void solve() {

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;

            int ti = i * a, tj = j * b;

            for (int dx = 0; dx < a; dx++) {
                for (int dy = 0; dy < b; dy++) {
                    ans[ti + dx][tj + dy] = c;
                }
            }

        }
    }

    for (int i = 0; i < n * a; i++) {
        for (int j = 0; j < m * b; j++) {
            cout << ans[i][j];
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