#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


int n, m;
int G[33][33];
int tmp[33][33];
bool used[33][33];
int ucnt[33][33];

struct D {
    int val;
    int x1, y1, x2, y2;

    void pf() {
        cout << val << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
    }
};


D track[33];

void choose(int cnt = 0) {
    if (cnt == m) {
        for (int i = 0; i < m; i++) {
            track[i].pf();
        }
        exit(0);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            tmp[i][j] = (used[i][j] ? 0 : G[i][j]) + tmp[i-1][j] + tmp[i][j-1] - tmp[i-1][j-1];
            ucnt[i][j] = (used[i][j] ? 1 : 0) + ucnt[i - 1][j] + ucnt[i][j - 1] - ucnt[i - 1][j - 1];
        }
    }

    int mx = -n * n * 1000;
    vector<pair<pair<int, int>, pair<int, int>>> lst;

    for (int x1 = 1; x1 <= n - 2; x1++) {
        for (int y1 = 1; y1 <= n - 2; y1++) {

            for (int x2 = x1 + 2; x2 <= n; x2++) {
                for (int y2 = y1 + 2; y2 <= n; y2++) {

                    int val = tmp[x2][y2] - tmp[x1 - 1][y2] - tmp[x2][y1 - 1] + tmp[x1 - 1][y1 - 1];
                    val -= tmp[x2 - 1][y2 - 1] - tmp[x1][y2 - 1] - tmp[x2 - 1][y1] + tmp[x1][y1];

                    int uc = ucnt[x2][y2] - ucnt[x1 - 1][y2] - ucnt[x2][y1 - 1] + ucnt[x1 - 1][y1 - 1];
                    uc -= ucnt[x2 - 1][y2 - 1] - ucnt[x1][y2 - 1] - ucnt[x2 - 1][y1] + ucnt[x1][y1];

                    if (uc) continue;
                    if (val > mx) {
                        mx = val;
                        lst.clear();
                        lst.push_back(mp(mp(x1, y1), mp(x2, y2)));
                    }
                    else if (val == mx) {
                        lst.push_back(mp(mp(x1, y1), mp(x2, y2)));
                    }
                }
            }

        }
    }

    for (auto& [a, b] : lst) {
        track[cnt] = { mx, a.x, a.y, b.x, b.y };

        for (int i = a.x; i <= b.x; i++) used[i][a.y] = used[i][b.y] = 1;
        for (int i = a.y; i <= b.y; i++) used[a.x][i] = used[b.x][i] = 1;

        choose(cnt + 1);
        for (int i = a.x; i <= b.x; i++) used[i][a.y] = used[i][b.y] = 0;
        for (int i = a.y; i <= b.y; i++) used[a.x][i] = used[b.x][i] = 0;
    }

}

void solve() {

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> G[i][j];
    }

    choose(0);

    cout << 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}