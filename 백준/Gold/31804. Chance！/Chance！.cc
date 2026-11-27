#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


int dist[2][1000101];
void solve() {
    memset(dist, -1, sizeof(dist));

    int a, b;
    cin >> a >> b;

    queue<pair<int, int>> q;
    q.push(mp(0, a));
    dist[0][a] = 0;
    while (!q.empty()) {

        auto [x, y] = q.front(); q.pop();

        if (y == b) {
            cout << dist[x][y];
            return;
        }

        if (y <= b && dist[x][y + 1] == -1) {
            dist[x][y + 1] = dist[x][y] + 1;
            q.push(mp(x, y + 1));
        }

        if (!x && y * 10 <= b && dist[1][y * 10] == -1) {
            dist[1][y * 10] = dist[x][y] + 1;
            q.push(mp(1, y * 10));
        }

        if (y * 2 <= b && dist[x][y * 2] == -1) {
            dist[x][y * 2] = dist[x][y] + 1;
            q.push(mp(x, y * 2));
        }

    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}