#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int n, m;
int dist[2][1010][1010];
int A[1010][1010];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}
void solve() {
    memset(dist, -1, sizeof(dist));

    cin >> m >> n;

    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
            if (A[i][j] == 2) {
                q.push(mp(0, mp(i, j)));
                dist[0][i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        int t = q.front().first;
        auto [a, b] = q.front().second;
        q.pop();

        if (A[a][b] == 3) {
            cout << dist[t][a][b] << '\n';
            return;
        }

        for (int i = 0; i < 4; i++) {
            int na = a + dx[i];
            int nb = b + dy[i];
            int nt = t;
            if (inGrid(na, nb) && A[na][nb] != 1) {
                if (A[na][nb] == 3 && t == 0) continue;
                if (A[na][nb] == 4) nt = 1;
                if (dist[nt][na][nb] == -1) {
                    dist[nt][na][nb] = dist[t][a][b] + 1;
                    q.push(mp(nt, mp(na, nb)));
                }
            }
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