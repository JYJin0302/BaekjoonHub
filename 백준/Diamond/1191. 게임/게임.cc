#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n;
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < n;
}
char G[333][333];
int dA[333][333];
int dB[333][333];
bool used[333][333];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

set<pair<int, int>> st[333][333];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
            dA[i][j] = dB[i][j] = -1;
            st[i][j].clear();
            used[i][j] = 0;
        }
    }

    int ax, ay, bx, by;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (G[i][j] == 'A') {
                tie(ax, ay) = mp(i, j);
            }
            if (G[i][j] == 'B') {
                tie(bx, by) = mp(i, j);
            }
        }
    }

    queue<pair<int, int>> q;
    q.push(mp(ax, ay));
    dA[ax][ay] = 0;
    while (!q.empty()) {

        auto [a, b] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int na = a + dx[i];
            int nb = b + dy[i];
            if (inGrid(na, nb) && G[na][nb] != '#' && dA[na][nb] == -1) {
                dA[na][nb] = dA[a][b] + 1;
                q.push(mp(na, nb));
            }
        }
    }

    q.push(mp(bx, by));
    dB[bx][by] = 0;
    while (!q.empty()) {

        auto [a, b] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int na = a + dx[i];
            int nb = b + dy[i];
            if (inGrid(na, nb) && G[na][nb] != '#' && dB[na][nb] == -1) {
                dB[na][nb] = dB[a][b] + 1;
                q.push(mp(na, nb));
            }
        }
    }


    //for (int i = 0; i < n; i++) {
    //    for (int j = 0; j < n; j++) {
    //        if (dA[i][j] == -1) cout << "X ";
    //        else cout << dA[i][j] << ' ';
    //    }
    //    cout << '\n';
    //}
    //cout << '\n';
    //for (int i = 0; i < n; i++) {
    //    for (int j = 0; j < n; j++) {
    //        if (dB[i][j] == -1) cout << "X ";
    //        else cout << dB[i][j] << ' ';
    //    }
    //    cout << '\n';
    //}

    if (dA[bx][by] & 1) {
        cout << "A\n";
        return;
    }

    int md = dA[bx][by] >> 1;
    vector<pair<int, pair<int, int>>> B;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            used[i][j] = (dB[i][j] + dA[i][j] == md * 2);
            if (dB[i][j] >= md && used[i][j]) {
                B.push_back(mp(dB[i][j], mp(i, j)));
            }
        }
    }
    sort(all(B));

    for (auto f : B) {
        int d = f.first;
        auto& [a, b] = f.second;

        if (d == md) {
            st[a][b].insert(mp(a, b));
        }
        else {
            map<pair<int, int>, int> tc;
            int cnt = 0;
            for (int i = 0; i < 4; i++) {
                int na = a + dx[i];
                int nb = b + dy[i];
                if (inGrid(na, nb) && dA[na][nb] == dA[a][b] + 1 && used[na][nb]) {
                    for (auto& [ta, tb] : st[na][nb]) {
                        for (int j = 0; j < 4; j++) {
                            int tna = ta + dx[j];
                            int tnb = tb + dy[j];

                            if (!inGrid(tna, tnb) || !used[tna][tnb] || dA[tna][tnb] != dA[ta][tb] + 1) continue;
                            int& res = tc[mp(tna, tnb)];
                            if (res & (1 << cnt)) {}
                            else res += 1 << cnt;
                        }
                    }

                    cnt++;
                }
            }

            for (const auto& p : tc) {
                if (p.second == (1 << cnt) - 1) {
                    st[a][b].insert(p.first);
                }
            }

            if (st[a][b].empty()) {
                cout << "A\n";
                return;
            }
        }
    }

    cout << "B\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}