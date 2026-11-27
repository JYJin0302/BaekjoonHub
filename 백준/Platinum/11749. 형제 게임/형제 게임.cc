#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c;
vector<int> adj[51];
bool adj_d[51][51][101]; // adj_d[x][y][d] : x에서 y까지 길이가 d인 경로의 존재여부
int dist[51];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dist, -1, sizeof(dist));

    cin >> n >> m >> a >> b >> c;
    while (m--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj_d[x][y][1] = 1;
    }

    for (int i = 1; i <= 99; i++) {
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= n; y++) {
                if (adj_d[x][y][i]) {
                    for (auto k : adj[y]) adj_d[x][k][i + 1] = 1;
                }
            }
        }
    }

    dist[n] = 0;
    for (int cnt = 0; cnt <= n; cnt++) {
        for (int i = 1; i <= n; i++) {
            if (dist[i] != -1) continue;

            int min_a = 10000, min_b = 10000, min_c = 10000;
            for (int j = 1; j <= n; j++) {
                if (dist[j] <= cnt && dist[j] != -1){
                    if (adj_d[i][j][a]) min_a = min(min_a, dist[j] + 1);
                    if (adj_d[i][j][b]) min_b = min(min_b, dist[j] + 1);
                    if (adj_d[i][j][c]) min_c = min(min_c, dist[j] + 1);
                }
            }

            int res = max({ min_a, min_b, min_c });
            if (res < 10000) {
                dist[i] = res;
            }
        }
    }

    if (dist[1] == -1) cout << "IMPOSSIBLE";
    else cout << dist[1];
}