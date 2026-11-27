#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using ld = long double;
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair

vector<int> adj[1010];

int L[101];

bool vis[1010];
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

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            adj[i].push_back(x);
        }
    }

    memset(L, -1, sizeof L);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof vis);
        if (go(i)) ans++;
    }
    cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}