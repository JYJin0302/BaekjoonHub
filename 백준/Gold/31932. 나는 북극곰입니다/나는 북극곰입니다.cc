#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

struct E {
    int u, v;
    ll d, t;
};
vector<E> adj[101010];

const ll INF = 0x3f3f3f3f3f3f3f3f;
ll dist[101010];

void solve() {
    
    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v;
        ll d, t;
        cin >> u >> v >> d >> t;
        adj[u].push_back({ u, v, d, t });
        adj[v].push_back({ u, v, d, t });
    }

    memset(dist, -1, sizeof dist);

    priority_queue<pair<ll, ll>> pq;
    pq.push(mp(INF, n));
    while (!pq.empty()) {
        auto [a, b] = pq.top(); pq.pop();
        if (dist[b] != -1) continue;
        if (a < 0) {
            break;
        }
        dist[b] = a;
        for (auto f : adj[b]) {
            int v = f.u + f.v - b;
            if (dist[v] == -1) {
                ll nval = min(f.t, a) - f.d;
                pq.push(mp(nval, v));
            }
        }

    }
    cout << dist[1] << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}