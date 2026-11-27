#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, m, k;
int dx[] = { 1, 0 };
int dy[] = { 0, -1 };
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}
char G[1010][1010];
int root[1010101];
int sz[1010101];
int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

void solve() {

    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> G[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (G[i][j] == '.') {
                sz[i * m + j] = 1;
                root[i * m + j] = i * m + j;
            }
        }
    }

    int ans = n - 1;
    while (ans >= 0) {

        bool ansFound = 0;
        for (int j = 0; j < m; j++){
            if (G[ans][j] == '.') {
                if (k == 1) {
                    ansFound = 1;
                    break;
                }
                int v = ans * m + j;
                v = find(v);

                for (int f = 0; f < 2; f++) {
                    int na = ans + dx[f];
                    int nb = j + dy[f];
                    if (inGrid(na, nb) && G[na][nb] == '.') {
                        int ti = na * m + nb;
                        ti = find(ti);

                        if (ti != v) {
                            root[ti] = v;
                            sz[v] += sz[ti];
                            if (sz[v] >= k) ansFound = 1;
                        }
                    }
                }


            }
        }

        if (ansFound) {
            cout << ans + 1 << '\n';
            return;
        }
        ans--;
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}