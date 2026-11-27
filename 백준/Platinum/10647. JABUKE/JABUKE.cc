#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


int n, m;
int U[505][505];
int D[505][505];

void upd(int col) {
    for (int i = n; i >= 1; i--) {
        if (D[i][col] != i) D[i][col] = D[i + 1][col];
    }

    for (int i = 1; i <= n; i++) {
        if (U[i][col] != i) U[i][col] = U[i - 1][col];
    }
}

void solve() {

    memset(U, -1, sizeof U);
    memset(D, -1, sizeof D);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c == 'x') {
                U[i][j] = D[i][j] = i;
            }
        }
    }
    
    for (int j = 1; j <= m; j++) {
        upd(j);
    }
    
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;

        int ans = n * n + m * m;
        for (int i = 1; i <= m; i++) {

            int ux = U[a][i];
            if (ux != -1) {
                ans = min(ans, (a - ux) * (a - ux) + (b - i) * (b - i));
            }
            ux = D[a][i];
            if (ux != -1) {
                ans = min(ans, (a - ux) * (a - ux) + (b - i) * (b - i));
            }
        }

        D[a][b] = U[a][b] = a;
        upd(b);
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}