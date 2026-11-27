#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> adj[101010];
int dfsn[101010];

int root[101010];
int deg[101010];
int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u != v) root[u] = v;
}

int ord = 0;
int dfs(int v, int pv = -1) {
    dfsn[v] = ++ord;
    int res = dfsn[v];
    bool ok = 0;
    for (auto f : adj[v]) {
        if (f == pv && !ok) {
            ok = 1;
            continue;
        }

        if (dfsn[f] != 0) {
            res = min(res, dfsn[f]);
            continue;
        }
        int val = dfs(f, v);
        res = min(res, val);

        if (val > dfsn[v]) {
            //cout << "Found: " <<  v << ' ' << f << '\n';
        }
        else {
            merge(v, f);
        }
    }
    return res;
}

void solve() {

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edgList;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b); 
        adj[b].push_back(a);
        edgList.push_back(mp(a, b));
    }

    for (int i = 1; i <= n; i++) root[i] = i;
    dfs(1);


    for (auto [a, b] : edgList) {
        a = find(a), b = find(b);
        if (a != b) {
            deg[a]++;
            deg[b]++;
            //cout << a << ' ' << b << '\n';
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) if (deg[i] == 1) cnt++;

    cout << (cnt + 1) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}