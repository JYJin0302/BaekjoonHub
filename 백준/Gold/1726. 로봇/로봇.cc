#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int n, m;
int A[101][101];
int dist[4][101][101];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, -1, 0, 1 };

int conv(int x) {
    
    switch (x) {
    case 1:
        return 3;
    case 2:
        return 1;
    case 3:
        return 0;
    case 4:
        return 2;
    }
}

bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m && A[x][y] == 0;
}
void solve() {    
    cin >> n >> m;

    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    int a, b, d;
    cin >> a >> b >> d;
    a--, b--;
    d = conv(d);

    int x, y, z;
    cin >> x >> y >> z;
    x--, y--;
    z = conv(z);

    dist[d][a][b] = 0;
    queue<pair<int, pair<int, int>>> q;
    q.push(mp(d, mp(a, b)));
    while (!q.empty()) {

        int a, b, d;
        tie(a, b) = q.front().second;
        d = q.front().first;
        q.pop();
        //cout << d << ' ' << a << ' ' << b << " | " << dist[d][a][b] << '\n';

        for (int k = 1; k < 4; k++) {
            int na = a + dx[d] * k;
            int nb = b + dy[d] * k;
            if (inGrid(na, nb) && dist[d][na][nb] == -1) {
                dist[d][na][nb] = dist[d][a][b] + 1;
                q.push(mp(d, mp(na, nb)));
            }
            else if (!inGrid(na, nb)) break;
        }

        for (int i = 1; i < 4; i += 2) {
            int nd = (d + i) % 4;
            if (dist[nd][a][b] == -1) {
                dist[nd][a][b] = dist[d][a][b] + 1;
                q.push(mp(nd, mp(a, b)));
            }
        }
    }

    cout << dist[z][x][y];

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}