#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> adj[1010];
ll C[1010];

ll n, m;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll dp[1010][1010];
ll sz[1010];
ll tot[1010];

ll ans = 0;
void dfs(int v) {

    sz[v] = 1;
    tot[v] = C[v];
    for (auto f : adj[v]) {
        dfs(f);
        sz[v] += sz[f];
        tot[v] += tot[f];
    }

    if (adj[v].size() == 0) {
        dp[v][0] = 0;
        dp[v][1] = C[v];
        return;
    }

    if (adj[v].size() == 1) {
        int c0 = adj[v][0];
        for (int i = 0; i <= sz[c0]; i++) {
            dp[v][i] = dp[c0][i];
        }
        dp[v][sz[v]] = tot[v];
        return;
    }

    int c0 = adj[v][0];
    int c1 = adj[v][1];

    for (int i = 0; i <= sz[c0]; i++) {
        for (int j = 0; j <= sz[c1]; j++) {
            ll val = 2 * max(dp[c0][i], dp[c1][j]);
            if (dp[c0][i] <= dp[c1][j] && dp[c0][i] == tot[c0]) val = dp[c0][i] + dp[c1][j];
            if (dp[c0][i] >= dp[c1][j] && dp[c1][j] == tot[c1]) val = dp[c0][i] + dp[c1][j];
            dp[v][i + j] = min(dp[v][i + j], val);
        }
    }
    dp[v][sz[v]] = tot[v];

    if (dp[c1][sz[c1]] <= m) {
        for (int i = 0; i <= sz[c0]; i++) {
            if (dp[c0][i] + dp[c1][sz[c1]] <= m) ans = max(ans, sz[c1] + i);
            else break;
        }
    }
    if (dp[c0][sz[c0]] <= m) {
        for (int i = 0; i <= sz[c1]; i++) {
            if (dp[c1][i] + dp[c0][sz[c0]] <= m) ans = max(ans, sz[c0] + i);
            else break;
        }
    }

}
void solve() {

    memset(dp, INF, sizeof dp);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> C[i];
    }

    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);

    }

    dfs(1);

    /*for (int i = 1; i <= n; i++) {
        cout << "RES: " << i << " | ";
        for (int j = 0; j <= sz[i]; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }*/

    for (int i = 1; i <= n; i++) {
        int ix = 0;
        while (ix <= sz[i] && dp[i][ix] <= m) ix++;

        ans = max(ans, ix - 1ll);
    }
    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}