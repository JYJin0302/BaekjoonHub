#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> root, dep;
vector<vector<ll>> dp, dist;
vector<vector<pair<ll, ll>>> adj;

int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

void dfs(int v, int pv = 0, int d = 1) {
    dep[v] = d;
    for (auto i : adj[v]) if (i.first != pv) {
        dp[0][i.first] = v;
        dist[0][i.first] = i.second;
        dfs(i.first, v, d+1);
    }
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    dep = vector<ll>(n + 1);
    adj = vector<vector<pair<ll, ll>>>(n + 1);
    root = vector<ll>(n + 1);

    vector<tuple<ll, ll, ll, ll>> edge;
    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        edge.push_back({ c, a, b, i });
    }

    sort(edge.begin(), edge.end());
    for (int i = 1; i <= n; i++) root[i] = i;

    // mst
    vector<ll> ans(m);
    ll mst = 0;
    for (auto i : edge) {
        ll a, b, c, d;
        tie(a, b, c, d) = i;

        find(b), find(c);
        if (root[b] != root[c]) {
            root[root[b]] = root[c];
            mst += a;
            adj[b].push_back({ c, a });
            adj[c].push_back({ b, a });
            ans[d] = -1;
        }
    }

    // sparse table
    int logn = log2(n) + 1;

    dp = vector<vector<ll>>(logn, vector<ll>(n + 1));
    dist = vector<vector<ll>>(logn, vector<ll>(n + 1));
    dfs(1);

    for (int i = 1; i < logn; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
            dist[i][j] = max(dist[i - 1][j], dist[i - 1][dp[i - 1][j]]);
        }
    }

    // query
    for (auto i : edge) {
        ll a, b, c, d;
        tie(a, b, c, d) = i;

        if (dep[b] > dep[c]) swap(b, c);

        int diff = dep[c] - dep[b];
        ll mdist = 0;

        for (int i = 0; i < logn; i++) {
            if (diff & (1 << i)) {
                mdist = max(mdist, dist[i][c]);
                c = dp[i][c];
            }
        }

        for (int i = logn - 1; i >= 0; i--) {
            if (dp[i][b] != dp[i][c]) {
                mdist = max({ mdist, dist[i][b], dist[i][c] });
                b = dp[i][b], c = dp[i][c];
            }
        }

        if (b != c) {
            mdist = max({ mdist, dist[0][b], dist[0][c] });
            b = dp[0][b];
        }

        ans[d] = mst - mdist + a;
    }

    for (ll i : ans) cout << i << '\n';
}