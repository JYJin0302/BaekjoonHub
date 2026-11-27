#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<pair<ll, ll>> adj[202020];

ll dist[202020];
ll dist2[202020];

void solve() {

    memset(dist, -1, sizeof(dist));
    memset(dist2, -1, sizeof(dist2));
    int n, x, y, k;
    cin >> n >> k >> x >> y;

    while (x--) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));
    }

    priority_queue<pair<ll, ll>> pq;
    pq.push(mp(0, 1));
    while (!pq.empty()) {
        auto [a, b] = pq.top(); pq.pop();
        if (dist[b] != -1) continue;
        dist[b] = -a;
        for (auto& [u, v] : adj[b]) {
            if (dist[u] == -1) {
                pq.push(mp(a - v, u));
            }
        }
    }

    while (y--) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));
    }

    pq.push(mp(0, n));
    while (!pq.empty()) {
        auto [a, b] = pq.top(); pq.pop();
        if (dist2[b] != -1) continue;
        dist2[b] = -a;
        for (auto& [u, v] : adj[b]) {
            if (dist2[u] == -1) {
                pq.push(mp(a - v, u));
            }
        }
    }

    ll ans = 1e18;
    if (dist[n] != -1) ans = dist[n];
    for (int i = 1; i <= n; i++) {
        if (dist[i] != -1 && dist2[i] != -1) ans = min(ans, max((ll)k, dist[i]) + dist2[i]);
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}