#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, m;
vector<int> adj[1010];
int dp[1010][1010]; // dp[a][b] : a의 b번째 자식들의 최댓값 ; dp[a][1] = a
int root[1010];
int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

bool merge(int &u, int &v) {
    u = find(u), v = find(v);
    if (u == v) return 0;
    if (u > v) swap(u, v);
    for (auto f : adj[u]) adj[v].push_back(f);
    for (int i = 1; i <= n; i++) {
        dp[v][i] = max(dp[v][i], dp[u][i]);
    }
    root[u] = v;
    return 1;
}

bool chk[1010][1010];
int depth[1010];

void solve() {

    cin >> n;

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        root[i] = i;
        for (int j = 1; j <= n; j++) dp[i][j] = 0;
    }

    vector<int> cnt(n + 1), P0(n+1);
    int r = -1;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
        P0[a] = b;
        cnt[a]++;
    }
    for (int i = 1; i <= n; i++) if (cnt[i] == 0) r = i;
    
    vector<int>P(n + 1);
    cin >> m;
    for (int i = 0; i < m - 1; i++) {
        int a, b;
        cin >> a >> b;
        P[a] = b;
    }

    for (int i = 1; i <= n; i++) {
        dp[i][1] = i;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int p = P0[j];
            if (p) dp[p][i] = max(dp[p][i], dp[j][i - 1]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            chk[i][j] = 0;
        }
    }

    queue<pair<int, int>> q2;
    vector<pair<int, int>> conn;
    for (int i = 1; i <= n; i++) {
        if (P[i] && P[i] != P0[i]) {
            q2.push(mp(P0[i], P[i]));
            chk[P0[i]][P[i]] = chk[P[i]][P0[i]] = 1;
        }
    }

    while (!q2.empty()) {
        conn.push_back(q2.front());
        auto [a, b] = q2.front(); q2.pop();

        if (P0[a] != P0[b] && !chk[P0[a]][P0[b]]) {
            chk[P0[a]][P0[b]] = chk[P0[b]][P0[a]] = 1;
            q2.push(mp(P0[a], P0[b]));
        }
    }

   // vector<int> depth(n + 1);
    depth[r] = 0;
    queue<int> q;
    q.push(r);
    while (!q.empty()) {
        int a = q.front(); q.pop();
        for (auto f : adj[a]) {
            q.push(f);
            depth[f] = depth[a] + 1;
        }
    }

    sort(all(conn), [](pair<int, int>& p1, pair<int, int>& p2) {
        return depth[p1.x] < depth[p2.x];
    });

    vector<pair<int, int>> ans;
    for (auto [a, b] : conn) {
        if (merge(a, b)) ans.push_back(mp(a, b));
    }

    q.push(r);
    while (!q.empty()) {

        int cur = q.front(); q.pop();
        sort(all(adj[cur]));
        
        int sz = adj[cur].size();
        for (int i = 0; i < sz; i++) {
            int u = adj[cur][i];
            if (find(u) != u) continue;
            if (P[u] == cur) {
                q.push(u);
                continue;
            }

            for (int j = i + 1; j < sz; j++) {
                int v = adj[cur][j];
                if (find(v) == v && P[v] == cur) {
                    bool ok = 1;
                    for (int k = 1; k <= n && ok; k++) {
                        if (dp[u][k] > dp[v][k]) ok = 0;
                        if (dp[u][k] == 0) break;
                    }
                    if (ok) {
                        merge(u, v);
                        ans.push_back(mp(u, v));
                        break;
                    }
                }
            }

        }
    }
    


    cout << ans.size() << '\n';
    for (auto [a, b] : ans) cout << a << ' ' << b << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}