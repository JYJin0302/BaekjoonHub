#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, k;
int dist[1001][1001];
string A[1001];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dist, -1, sizeof(dist));
    cin >> n >> m >> k;
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--, x2--, y1--, y2--;

    queue<pair<int, int>> q;
    q.push({ x1, y1 });
    dist[x1][y1] = 0;
    while (!q.empty()) {

        int a, b;
        tie(a, b) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int na = a;
            int nb = b;

            for (int j = 1; j <= k; j++) {
                na += dx[i];
                nb += dy[i];
                if (inGrid(na, nb) && A[na][nb] == '.') {
                    if (dist[na][nb] == -1) {
                        dist[na][nb] = dist[a][b] + 1;
                        q.push({ na, nb });
                    }
                    else if (dist[na][nb] != dist[a][b] + 1) {
                        break;
                    }
                }
                else break;
            }
        }
    }
    cout << dist[x2][y2];
}