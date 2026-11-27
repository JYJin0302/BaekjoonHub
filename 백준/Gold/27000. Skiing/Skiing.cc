#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


ld v;
int n, m;
int H[101][101];
ld dist[101][101];
ld V[101][101];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1,0,-1 };
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}
void solve() {

    cin >> v >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> H[i][j];
            dist[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            int dif = H[0][0] - H[i][j];
            ld res = v;
            if (dif >= 0) {
                while (dif--) res *= 2;
            }
            else {
                while (dif < 0) {
                    res *= 0.5;
                    dif++;
                }
            }
            V[i][j] = 1 / res;
        }
    }

    priority_queue<pair<ld, pair<int, int>>> pq;
    pq.push(mp(0, mp(0, 0)));
    while (!pq.empty()) {
        ld val = pq.top().x;
        auto [a, b] = pq.top().y;
        pq.pop();

        if (dist[a][b] < -0.5) dist[a][b] = -val;
        else continue;

        //cout << a << ' ' << b << " = " << val << '\n';

        for (int i = 0; i < 4; i++) {
            int na = a + dx[i];
            int nb = b + dy[i];
            if (inGrid(na, nb) && dist[na][nb] < -0.5) {
                pq.push(mp(val - V[a][b], mp(na, nb)));
            }
        }
    }

    cout << fixed << setprecision(2);
    cout << dist[n - 1][m - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}