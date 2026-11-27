#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


int n;
char G[101][101];

int dx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int dy[] = { 1, 1, 1, 0, -1, -1, -1, 0 };
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < n;
}
void solve() {
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
        }
    }

    int ans = 0;
    string res = "MOBIS";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (G[i][j] != 'M') continue;
            for (int d = 0; d < 8; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];

                bool ok = 1;
                for (int f = 1; f < 5; f++) {
                    if (inGrid(ni, nj) && G[ni][nj] == res[f]) {
                        ni += dx[d];
                        nj += dy[d];
                    }
                    else ok = 0;
                }
                ans += ok;
            }

        }
    }
    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}