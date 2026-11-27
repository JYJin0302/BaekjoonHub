#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int n, m;
int A[501][510];
int rep[250001];
bool f[250001];
bool l[250001];

bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}
void solve() {


    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    // init
    for (int i = 0; i < n * m; i++) {
        f[i] = 0;
        l[i] = 0;
        rep[i] = 0;
    }

    int cnt = 0;
    for (int x = 0; x < n * m; x++) {
        if (rep[x] == 0) {
            cnt++;
            rep[x] = cnt;

            // bfs
            queue<int> q;
            q.push(x);
            while (!q.empty()) {

                int a = q.front();
                q.pop();

                int ix = a / m, iy = a % m;
                for (int i = 0; i < 4; i++) {
                    int nx = ix + dx[i];
                    int ny = iy + dy[i];

                    if (inGrid(nx, ny) && A[nx][ny] == A[ix][iy] && rep[nx * m + ny] == 0) {
                        rep[nx * m + ny] = cnt;
                        q.push(nx * m + ny);
                    }
                }
            }
        }
    }

    for (int x = 0; x < n * m; x++) {

        int ix = x / m, iy = x % m;

        for (int i = 0; i < 4; i++) {
            int nx = ix + dx[i];
            int ny = iy + dy[i];

            if (inGrid(nx, ny) && A[nx][ny] < A[ix][iy]) {

                int nv = nx * m + ny;
                f[rep[nv]] = 1;
                l[rep[x]] = 1;
            }
        }
    }

    int cnt1 = 0, cnt2 = 0;

    for (int i = 1; i <= cnt; i++) {
        if (!f[i] && !l[i]) continue;
        if (!f[i]) cnt1++;
        if (!l[i]) cnt2++;
    }
    if(cnt == 1) cout << "0\n";
    else cout << max(cnt1, cnt2) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}