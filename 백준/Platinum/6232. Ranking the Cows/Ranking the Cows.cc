#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

bitset<1010> bs[1010];
vector<int> adj[1010];

bool vis[1010];
void dfs(int  v, int pv = -1) {
    vis[v] = 1;
    for (auto f : adj[v]) {
        if (!vis[f]) dfs(f);
        bs[v] |= bs[f];
    }
}

bool kn[1010][1010];

void solve() {

    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        bs[a][b] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (bs[i][j]) kn[i][j] = kn[j][i] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (!kn[i][j]) {
                ans++;
                //cout << i << ' ' << j << '\n';
                kn[i][j] = kn[j][i] = 1;
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