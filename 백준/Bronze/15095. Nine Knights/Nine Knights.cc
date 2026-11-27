#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int n = 5;

char grid[5][5];

int dx[] = { -2, -2, -1,  1, 2, 2, 1, -1 };
int dy[] = { 1, -1, -2, -2, -1, 1, 2, 2, 1 };
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < n;
}

void solve() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int cnt = 0;
    bool ok = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] != 'k')  continue;
            cnt++;
            for (int k = 0; k < 8; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if (inGrid(ni, nj) && grid[ni][nj] == 'k') ok = 0;
            }
        }
    }

    if (cnt != 9) ok = 0;

    if (ok) cout << "valid";
    else cout << "invalid";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

}