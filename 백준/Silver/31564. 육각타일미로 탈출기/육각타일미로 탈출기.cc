#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int n, m, k;
bool A[1010][1010];

int dEx[] = { -1, 0, 1, 0 , -1, 1};
int dEy[] = { 0 , 1, 0, -1 , -1, -1};
int dOx[] = { -1, 0, 1, 0 , -1 , 1};
int dOy[] = { 0 , 1, 0, -1 , 1, 1};

int dist[1010][1010];

bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m && !A[x][y];
}

void solve() {

    memset(dist, -1, sizeof(dist));
    cin >> n >> m >> k;
    while (k--) {
        int a, b;
        cin >> a >> b;
        A[a][b] = 1;
    }

    dist[0][0] = 0;
    queue<pair<int, int>> q;
    q.push(mp(0, 0));
    while (!q.empty()) {
        auto [a, b] = q.front();
        q.pop();

        if (a & 1) {
            for (int j = 0; j < 6; j++) {
                int na = a + dOx[j];
                int nb = b + dOy[j];
                if (inGrid(na, nb) && dist[na][nb] == -1) {
                    dist[na][nb] = dist[a][b] + 1;
                    q.push(mp(na, nb));
                }
            }
        }
        else {
            for (int j = 0; j < 6; j++) {
                int na = a + dEx[j];
                int nb = b + dEy[j];
                if (inGrid(na, nb) && dist[na][nb] == -1) {
                    dist[na][nb] = dist[a][b] + 1;
                    q.push(mp(na, nb));
                }
            }
        }
    }

    cout << dist[n - 1][m - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}