#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<int, int>> adj[200001];
int topo[200001], rep[200001];
int dist[200001], spt[20][200001], spt2[20][200001];
int dep[200001];
bool inCycle[200001];

vector<int> seg;

void update(int l, int r, int n, int u, int v) {
    if (l > u || r < u) return;
    if (l == u && r == u) {
        seg[n] = v;
        return;
    }

    int m = (l + r) >> 1;
    update(l, m, n * 2, u, v);
    update(m + 1, r, n * 2 + 1, u, v);
    seg[n] = min(seg[n * 2], seg[n * 2 + 1]);
}

int ssum(int l, int r, int n, int sl, int sr) {
    if (l > sr || r < sl) return 1e7;
    if (l >= sl && r <= sr) return seg[n];

    int m = (l + r) >> 1;
    return min(ssum(l, m, n*2, sl, sr), ssum(m + 1, r, n * 2 + 1, sl, sr));
}

void dfs(int v, int pv = -1) {

    for (auto i : adj[v]) {
        int a, b;
        tie(a, b) = i;

        if (a != pv && !inCycle[a]) {
            rep[a] = rep[v];
            dep[a] = dep[v] + 1;
            spt[0][a] = v;
            spt2[0][a] = b;
            dist[a] = min(dist[v], b);

            dfs(a, v);
        }
    }
}

int getLCA(int u, int v) {
    int res = 10000000;

    if (dep[u] > dep[v]) swap(u, v);
    int df = dep[v] - dep[u];
    for (int i = 0; i < 20; i++) {
        if (df & (1 << i)) {
            res = min(res, spt2[i][v]);
            v = spt[i][v];
        }
    }

    for (int i = 19; i >= 0; i--) {
        if (spt[i][u] != spt[i][v]) {
            res = min(res, spt2[i][u]);
            res = min(res, spt2[i][v]);
            u = spt[i][u];
            v = spt[i][v];
        }
    }

    if (u != v) {
        res = min({ res, spt2[0][u], spt2[0][v] });
        u = spt[0][u];
    }
    return res;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // initialzie
    for (int i = 1; i <= n; i++) {
        inCycle[i] = 1;
        rep[i] = i;
        dist[i] = 1e7;
        spt2[0][i] = 1e7;
    }
    int cnt = n;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
        topo[a]++; topo[b]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (topo[i] == 1) q.push(i);
    }

    while (!q.empty()) {

        int a = q.front();
        q.pop();
        inCycle[a] = 0;
        cnt--;
        for (auto i : adj[a]) {
            int b, c;
            tie(b, c) = i;

            topo[b]--;
            if (topo[b] == 1) q.push(b);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (inCycle[i]) dfs(i);
    }

    // fill sprase table
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            int tj = spt[i - 1][j];
            spt[i][j] = spt[i - 1][tj];
            spt2[i][j] = min(spt2[i - 1][j], spt2[i - 1][tj]);
        }
    }

    vector<int> cyc, cycIdx(n + 1);
    int ix = 0, px = -1;
    for (int i = 1; i <= n; i++) {
        if (inCycle[i]) {
            ix = i;
            break;
        }
    }

    int sz = 1;
    while (sz < cnt) sz *= 2;
    seg = vector<int>(sz * 2, 1e7);

    int tdx = 0;
    cyc.push_back(ix);
    while (cyc.size() == 1 || cyc.back() != cyc[0]) {
        int nx = -1;
        for (auto i : adj[ix]) if (i.first != px && inCycle[i.first]) {
            nx = i.first;
            //cout << "ADD: " << i.second << '\n';
            update(0, sz - 1, 1, tdx, i.second);
            cycIdx[nx] = tdx;
            tdx++;
            break;
        }
        cyc.push_back(nx);
        px = ix;
        ix = nx;
    }

    

    while (m--) {

        int a, b;
        cin >> a >> b;

        int ta = rep[a], tb = rep[b];

        if (ta == tb) {
            cout << getLCA(a, b) << '\n';
        }
        else {

            int ans = 1e7;
            ans = min(dist[a], dist[b]);

            int ai = cycIdx[ta], bi = cycIdx[tb];

            if (ai > bi) swap(ai, bi);

            int val1 = ssum(0, sz - 1, 1, ai + 1, bi);
            int val2 = min(ssum(0, sz - 1, 1, 0, ai), ssum(0, sz - 1, 1, bi + 1, cnt - 1));

            ans = min(ans, val1 + val2);
            cout << ans << '\n';
        }
    }
}