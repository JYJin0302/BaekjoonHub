#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll, ll>> adj[200001];
int topo[200001], rep[200001];
ll dist[200001], spt[20][200001];
int dep[200001];
bool inCycle[200001];

void dfs(int v, int pv = -1) {

    for (auto i : adj[v]) {
        ll a, b;
        tie(a, b) = i;

        if (a != pv && !inCycle[a]) {
            rep[a] = rep[v];
            dep[a] = dep[v] + 1;
            spt[0][a] = v;
            dist[a] = dist[v] + b;
            dfs(a, v);
        }
    }
}

int getLCA(int u, int v) {

    if (dep[u] > dep[v]) swap(u, v);
    int df = dep[v] - dep[u];
    for (int i = 0; i < 20; i++) {
        if (df & (1 << i)) v = spt[i][v];
    }

    for (int i = 19; i >= 0; i--) {
        if (spt[i][u] != spt[i][v]) {
            u = spt[i][u];
            v = spt[i][v];
        }
    }

    if (u != v) u = spt[0][u];
    return u;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    while (n) {

        // initialize
        for (int i = 0; i < n; i++) {
            adj[i].clear();
            topo[i] = 0;
            rep[i] = i;
            dist[i] = 0;
            dep[i] = 0;
            inCycle[i] = 1;
        }

        vector<tuple<ll, ll, ll>> edge(n);
        for (int i = 0; i < n; i++) {
            ll a, b, c;
            cin >> a >> b >> c;
            if (a > b) swap(a, b);
            edge[i] = { a, b, c };
        }

        sort(edge.begin(), edge.end());
        for (int i = 0; i < n; i++) {
            if (i == 0 || get<0>(edge[i - 1]) != get<0>(edge[i]) || get<1>(edge[i - 1]) != get<1>(edge[i])) {
                ll a, b, c;
                tie(a, b, c) = edge[i];
                adj[a].push_back({ b, c });
                adj[b].push_back({ a ,c });
                topo[a]++, topo[b]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (topo[i] == 1) q.push(i);
        }

        while (!q.empty()) {
            int a = q.front();
            q.pop();
            inCycle[a] = 0;

            for (auto i : adj[a]) {
                int x, y;
                tie(x, y) = i;
                topo[x]--;
                if (topo[x] == 1) q.push(x);
            }
        }

        bool ok = 0;
        for (int i = 0; i < n; i++) {
            if (inCycle[i]) {
                rep[i] = i;
                dfs(i);
                ok = 1;
            }
        }
        if (!ok) dfs(0);

        for (int i = 1; i < 20; i++) {
            for (int j = 0; j < n; j++) {
                spt[i][j] = spt[i - 1][spt[i - 1][j]];
            }
        }
        for (int i = 0; i < n; i++) {
            if (inCycle[i]) {
                int curr = i;
                while (curr != -1) {
                    int nx = -1;
                    for (auto k : adj[curr]) {
                        int a, b;
                        tie(a, b) = k;
                        if (rep[a] == a && !inCycle[a]) {
                            rep[a] = rep[curr];
                            nx = a;
                            dist[a] = dist[curr] + b;
                        }
                    }
                    curr = nx;
                }
            }
        }

        vector<int> tx;
        vector<ll> tdist = { 0 };
        vector<int> txIdx(n + 1);

        int ix = 0, pv = -1;
        for (int i =0; i <n; i++) {
            if (inCycle[i]) {
                ix = i; break;
            }
        }

        tx.push_back(ix);
        while (tx.size() == 1 || ix != tx[0]) {
            int nx = 0;
            for (auto i : adj[ix]) {
                int a, b;
                tie(a, b) = i;
                if (inCycle[a] && a != pv) {
                    nx = a;
                    tdist.push_back(tdist.back() + b);
                    break;
                }
            }
            tx.push_back(nx);
            pv = ix;
            ix = nx;
        }

        for (int i = 0; i < tx.size(); i++) {
            txIdx[tx[i]] = i;
        }
        /*
        for (auto i : tx) cout << i << ' ';
        cout << '\n';
        for (auto i : tdist) cout << i << ' ';
        cout << '\n';

        for (int i = 1; i <= n; i++) {
            cout << rep[i] << ' ' << dist[i] << ' ' << inCycle[i] << '\n';
        }
        */

        int Q;
        cin >> Q;
        while (Q--) {

            int a, b;
            cin >> a >> b;

            if (rep[a] == rep[b]) {
                int lc = getLCA(a, b);
                ll res = dist[a] + dist[b] - dist[lc] * 2;
                cout << res << '\n';
                continue;
            }

            ll ans = dist[a] + dist[b];
            int ta = txIdx[rep[a]], tb = txIdx[rep[b]];
            ll tans = abs(tdist[ta] - tdist[tb]);
            tans = min(tans, tdist.back() - tans);
            cout << ans + tans << '\n';

        }

        cin >> n;
    }

}