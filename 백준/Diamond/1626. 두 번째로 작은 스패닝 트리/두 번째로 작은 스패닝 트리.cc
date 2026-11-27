#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> root, dep;
vector<vector<ll>> dp, dist, ddist;
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
        ddist[0][i.first] = i.second;
        dfs(i.first, v, d + 1);
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
    vector<bool> used(m);
    int cnt = 0;
    ll mst = 0;
    for (auto i : edge) {
        ll a, b, c, d;
        tie(a, b, c, d) = i;

        find(b), find(c);
        if (root[b] != root[c]) {
            used[d] = 1;
            root[root[b]] = root[c];
            mst += a;
            adj[b].push_back({ c, a });
            adj[c].push_back({ b, a });
            cnt++;
        }
    }

    if (cnt != n - 1) {
        cout << -1;
        return 0;
    }

    // sparse table
    int logn = log2(n) + 1;

    dp = vector<vector<ll>>(logn, vector<ll>(n + 1));
    dist = vector<vector<ll>>(logn, vector<ll>(n + 1));
    ddist = vector<vector<ll>>(logn, vector<ll>(n + 1));
    dfs(1);

    for (int i = 1; i < logn; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
            dist[i][j] = max(dist[i - 1][j], dist[i - 1][dp[i - 1][j]]);
            ddist[i][j] = dist[i][j];
            //find
            vector<ll> temp = { dist[i - 1][j], dist[i - 1][dp[i - 1][j]], ddist[i - 1][j], ddist[i - 1][dp[i - 1][j]] };
            sort(temp.rbegin(), temp.rend());
            for (ll k : temp) {
                if (k != ddist[i][j]) {
                    ddist[i][j] = k;
                    break;
                }
            }
        }
    }

    // query
    ll ans = mst;
    
    for (auto i : edge) {
        ll a, b, c, d;
        tie(a, b, c, d) = i;
        vector<ll> temp;
        if (used[d]) continue;
        if (dep[b] > dep[c]) swap(b, c);

        int diff = dep[c] - dep[b];
        ll mdist = 0;

        for (int i = 0; i < logn; i++) {
            if (diff & (1 << i)) {
                temp.push_back(dist[i][c]);
                temp.push_back(ddist[i][c]);
                c = dp[i][c];
            }
        }

        for (int i = logn - 1; i >= 0; i--) {
            if (dp[i][b] != dp[i][c]) {
                temp.push_back(dist[i][b]);
                temp.push_back(dist[i][c]);
                temp.push_back(ddist[i][b]);
                temp.push_back(ddist[i][c]);
                b = dp[i][b], c = dp[i][c];
            }
        }

        if (b != c) {
            temp.push_back(dist[0][b]);
            temp.push_back(dist[0][c]);
            temp.push_back(ddist[0][b]);
            temp.push_back(ddist[0][c]);
            b = dp[0][b];
        }

        sort(temp.rbegin(), temp.rend());
        ll MM = temp[0], mm = -1;
        for (ll i : temp) if (i != MM) {
            mm = i;
            break;
        }

        ll ndist = mst - MM + a;
        if (ndist == mst && mm != -1) ndist = mst - mm + a;

        if (ndist != mst) {
            if (ans == mst) ans = ndist;
            else ans = min(ans, ndist);
        }
    }

    if (ans == mst) cout << -1;
    else cout << ans;
}