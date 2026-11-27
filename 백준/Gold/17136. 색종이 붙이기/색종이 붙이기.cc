#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int G[11][11];
int cur[6];

int ans = 100;
bool fil[11][11];
void choose(int x, int y, int cnt = 0) {
    if (y == 10) {
        choose(x + 1, 0, cnt);
        return;
    }

    if (x == 10 && y == 0) {
        ans = min(ans, cnt);
        return;
    }

    if (G[x][y] == 0 || fil[x][y]) {
        choose(x, y + 1, cnt);
        return;
    }

    for (int i = 5; i >= 1; i--) {
        if (x + i > 10 || y + i > 10 || cur[i] == 0) continue;

        bool ok = 1;
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < i; k++) {
                if (!G[x+j][y+k] || fil[x+j][y+k]) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) break;
        }

        if (ok) {
            for (int j = 0; j < i; j++) {
                for (int k = 0; k < i; k++) {
                    fil[x+j][y+k] = 1;
                }
            }
            cur[i]--;

            choose(x, y + 1, cnt + 1);

            cur[i]++;
            for (int j = 0; j < i; j++) {
                for (int k = 0; k < i; k++) {
                    fil[x+j][y+k] = 0;
                }
            }
        }
    }

}

void solve() {

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> G[i][j];
        }
    }

    for (int i = 1; i <= 5; i++) cur[i] = 5;
    choose(0, 0);

    if (ans == 100) ans = -1;
    cout << ans;
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