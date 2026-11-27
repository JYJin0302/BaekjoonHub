#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int A[1010][1010];
int ans[1010][1010];
bool vis[1010][1010];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

void solve() {
    memset(ans, -1, sizeof(ans));

    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> B;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
            B.push_back(mp(A[i][j], mp(i, j)));
        }
    }
    sort(all(B));

    for (auto& f : B) {
        int val = f.first;
        auto& [x, y] = f.second;

        if (vis[x][y]) continue;
        vis[x][y] = 1;
        queue<pair<int, int>> q;
        q.push(mp(x, y));

        int mx = -1;
        vector<pair<int, int>> vList;
        while (!q.empty()) {
            auto [a, b] = q.front(); q.pop();
            vList.push_back(mp(a, b));
            for (int i = 0; i < 4; i++) {
                int na = a + dx[i];
                int nb = b + dy[i];
                if (A[na][nb] == val && !vis[na][nb]) {
                    vis[na][nb] = 1;
                    q.push(mp(na, nb));
                }
                else if (A[na][nb] < val) {
                    mx = max(mx, ans[na][nb]);
                }
            }
        }

        for (auto& [a, b] : vList) {
            ans[a][b] = mx + 1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}