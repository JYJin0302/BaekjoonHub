#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

int n, m;
bool vis[1010][1010];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}

void solve() {

    cin >> m >> n;

    vector<string> A(n);
    for (auto& i : A) cin >> i;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == '*' && !vis[i][j]) {
                vis[i][j] = 1;
                int cnt = 0;
                queue<pair<int, int>> q;
                q.push(mp(i, j));
                while (!q.empty()) {
                    auto [a, b] = q.front(); q.pop();
                    cnt++;
                    for (int k = 0; k < 4; k++) {
                        int na = a + dx[k];
                        int nb = b + dy[k];
                        if (inGrid(na, nb) && !vis[na][nb] && A[na][nb] == '*') {
                            vis[na][nb] = 1;
                            q.push(mp(na, nb));
                        }
                    }

                }
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}