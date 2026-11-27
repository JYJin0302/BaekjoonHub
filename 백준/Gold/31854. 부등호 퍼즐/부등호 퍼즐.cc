#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n;

int topo[1010][1010];
int ans[1010][1010];
vector<pair<int, int>> adj[1010][1010];

void solve() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            char c;
            cin >> c;
            if (c == '<') {
                adj[i][j].push_back(mp(i, j+1));
                topo[i][j + 1]++;
            }
            else {
                adj[i][j + 1].push_back(mp(i, j));
                topo[i][j]++;
            }
        }
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == '<') {
                adj[i][j].push_back(mp(i+1, j));
                topo[i+1][j]++;
            }
            else {
                adj[i+1][j].push_back(mp(i, j));
                topo[i][j]++;
            }
        }
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (topo[i][j] == 0) q.push(mp(i, j));
        }
    }

    int cur = 1;
    while (!q.empty()) {
        auto [a, b] = q.front(); q.pop();
        ans[a][b] = cur++;
        for (auto [x, y] : adj[a][b]) {
            topo[x][y]--;
            if (topo[x][y] == 0) q.push(mp(x, y));
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
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