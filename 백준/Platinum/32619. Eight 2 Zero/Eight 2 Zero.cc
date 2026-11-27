#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<int> adj[303030];
vector<pair<int, int>> nedg;

int dfsn[303030];
int ord = 0;
int dfs(int v, int pv = -1) {
    dfsn[v] = ++ord;
    int ret = dfsn[v];
    for (auto f : adj[v]) if (f != pv) {

        if (dfsn[f] == -1) {
            int tmp = dfs(f, v);
            if (tmp <= dfsn[v]) {
                nedg.push_back(mp(v, f));
            }
            ret = min(ret, tmp);
        }
        else {
            ret = min(ret, dfsn[f]);
            if (dfsn[f] > dfsn[v]) nedg.push_back(mp(v, f));
        }
    }
    return ret;
}


void solve() {

    int n;
    cin >> n;

    memset(dfsn, -1, sizeof dfsn);

    for (int i = 0; i < n + 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    int ans = n + 1 - nedg.size();

    for (int i = 1; i <= n; i++) adj[i].clear();
    for (auto [a, b] : nedg) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int s = -1;
    vector<int> r;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 3) r.push_back(i);
        if (adj[i].size() == 4) s = i;
    }

    if (!r.empty()) {
        assert(r.size() == 2);

        int a = r[0], b = r[1];

        vector<int> dist(n + 1, -1);
        dist[a] = 0;
        queue<int> q;
        q.push(a);
        while (!q.empty()) {
            int f = q.front(); q.pop();

            for (auto d : adj[f]) {
                if (dist[d] == -1) {
                    dist[d] = dist[f] + 1;
                    q.push(d);
                }
            }
        }

        ans += dist[b];
    }
    if (s != -1) {
        vector<int> dist(n + 1, -1);
        queue<int> q;
        dist[s] = 0;
        int val = n + 10;
        q.push(s);
        while (!q.empty()) {
            int a = q.front(); q.pop();

            for (auto f : adj[a]) {
                if (dist[f] == -1) {
                    dist[f] = dist[a] + 1;
                    q.push(f);
                }
                else if (dist[f] + 1 != dist[a]) {
                    val = min(val, dist[f] + dist[a] + 1);
                }
            }
        }
        ans += val;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

}
