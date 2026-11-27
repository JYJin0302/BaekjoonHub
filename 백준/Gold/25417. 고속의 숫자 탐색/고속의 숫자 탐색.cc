#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int A[6][6];
int dist[6][6];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool inGrid(int x, int y) {
    return min(x, y) >= 0 && max(x, y) < 5;
}

void solve() {
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> A[i][j];
        }
    }

    int ix, iy;
    cin >> ix >> iy;

    dist[ix][iy] = 0;
    queue<pair<int, int>> q;
    q.push(mp(ix, iy));

    while (!q.empty()) {
        int a, b;
        tie(a, b) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int na = a + dx[i];
            int nb = b + dy[i];

            if (inGrid(na, nb) && dist[na][nb] == -1 && A[na][nb] != -1) {
                dist[na][nb] = dist[a][b] + 1;
                q.push(mp(na, nb));
            }

            while (inGrid(na, nb) && A[na][nb] != -1) {
                if (A[na][nb] == 7) break;
                na += dx[i];
                nb += dy[i];
            }

            if (inGrid(na, nb) && A[na][nb] == 7) {}
            else {
                na -= dx[i];
                nb -= dy[i];
            }

            if (dist[na][nb] == -1) {
                dist[na][nb] = dist[a][b] + 1;
                q.push(mp(na, nb));
            }
        }
    }
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (A[i][j] == 1) {
                cout << dist[i][j] << '\n';
                return;
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