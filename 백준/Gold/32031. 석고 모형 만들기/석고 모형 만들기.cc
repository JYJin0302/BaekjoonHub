#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, m;
vector<int> adj[101010];
bool vis[101010];

int getIdx(int x, int y, int z) {
    return z * (n +1) * (m+1) + x * (m + 1) + y;
}

void solve() {
    
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;

            if (c == 'H') {
                for (int dx = 0; dx < 2; dx++) {
                    for (int dy = 0; dy < 2; dy++) {
                        int v = getIdx(i + dx, j, dy);
                        int u = getIdx(i + dx, j + 1, dy);
                        adj[v].push_back(u);
                        adj[u].push_back(v);
                    }
                }
            }
            else if (c == 'I') {
                for (int dx = 0; dx < 2; dx++) {
                    for (int dy = 0; dy < 2; dy++) {
                        int v = getIdx(i, j + dx, dy);
                        int u = getIdx(i + 1, j + dx, dy);
                        adj[v].push_back(u);
                        adj[u].push_back(v);
                    }
                }
            }
            else {
                for (int dx = 0; dx < 2; dx++) {
                    for (int dy = 0; dy < 2; dy++) {
                        int v = getIdx(i + dx, j + dy, 0);
                        int u = getIdx(i + dx, j + dy, 1);
                        adj[v].push_back(u);
                        adj[u].push_back(v);
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < (n+1) * (m+1) * 2; i++) {
        if (vis[i]) continue;
        ans++;
        vis[i] = 1;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int a = q.front(); q.pop();
            for (auto f : adj[a]) if (!vis[f]) {
                vis[f] = 1; q.push(f);
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