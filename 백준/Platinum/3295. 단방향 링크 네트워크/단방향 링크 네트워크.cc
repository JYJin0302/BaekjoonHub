#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
#define mp make_pair
#define all(x) x.begin(), x.end()


int L[1010];
bool vis[1010];
vector<int> adj[1010];
bool go(int v) {
    if (vis[v]) return 0;
    vis[v] = 1;
    for (auto f : adj[v]) {
        if (L[f] == -1 || go(L[f])) {
            L[f] = v;
            return 1;
        }
    }
    return 0;
}

void solve() {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        L[i] = -1;
        adj[i].clear();
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) vis[j] = 0;
        if (go(i)) ans++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}