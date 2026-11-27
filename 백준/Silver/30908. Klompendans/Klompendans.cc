#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n;
bool G[2][505][505];

int dx[] = { -1, -1, 1, 1 };
int dy[] = { -1, 1, -1, 1 };

bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < n;
}

void solve() {
    cin >> n;

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    queue<pair<int, pair<int, int>>> q;
    q.push(mp(0, mp(0, 0)));
    q.push(mp(1, mp(0, 0)));
    G[0][0][0] = G[1][0][0] = 1;

    while (!q.empty()) {
        int t = q.front().x;
        auto [ta, tb] = q.front().y;
        q.pop();

        for (int i = 0; i < 4; i++) {

            int na = ta;
            int nb = tb;

            if (t) na += dx[i] * c, nb += dy[i] * d;
            else na += dx[i] * a, nb += dy[i] * b;

            if (inGrid(na, nb) && !G[1 - t][na][nb]) {
                G[1 - t][na][nb] = 1;
                q.push(mp(1 - t, mp(na, nb)));
            }
        }

        swap(a, b);
        swap(c, d);
        for (int i = 0; i < 4; i++) {

            int na = ta;
            int nb = tb;

            if (t) na += dx[i] * c, nb += dy[i] * d;
            else na += dx[i] * a, nb += dy[i] * b;

            if (inGrid(na, nb) && !G[1 - t][na][nb]) {
                G[1 - t][na][nb] = 1;
                q.push(mp(1 - t, mp(na, nb)));
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (G[0][i][j] || G[1][i][j]) {
                cnt++;
            }
        }
    }
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}