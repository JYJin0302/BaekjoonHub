#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

int n, d;
int Col[11][11], Row[11][11];
int ans[11][11];

bool chk(int x, int y) {
    int cnt = 0;
    for (int j = 0; j < d; j++) {
        if (Row[x][j] != 0) cnt++;
    }
    if (n - y - 1 < d - cnt) return 0;
    cnt = 0;
    for (int j = 0; j < d; j++) {
        if (Col[y][j] != 0) cnt++;
    }
    if (n - x - 1 < d - cnt) return 0;

    return 1;
}

bool fill(int x, int y) {

    /*cout << string(10, '-') << x << ' ' << y << '\n';
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            cout << ans[j][k];
        }
        cout << '\n';
    }*/

    if (x == n) {
        return 1;
    }

    for (int i = 0; i < d; i++) {
        ans[x][y] = i;
        Row[x][i]++;
        Col[y][i]++; 
        if (y == n - 1) {
            // check
            bool ok = 1;
            for (int j = 0; j < d; j++) {
                if (Row[x][j] == 0) ok = 0;
            }
            if (ok && chk(x, y) && fill(x + 1, 0)) return 1;
        }
        else{
            if ( chk(x, y) && fill(x, y + 1)) return 1;
        }
        Row[x][i]--;
        Col[y][i]--;
    }
    return 0;

}

void solve() {
    cin >> n >> d;
    fill(0, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}