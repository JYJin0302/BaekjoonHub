#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<pair<ll, ll>> adj[202020];
ll dist[202020];
void solve() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));
    }
    memset(dist, -1, sizeof(dist));

    priority_queue<pair<ll, pair<ll, ll>>> pq;
    pq.push(mp(0, mp(0, 1)));
    ll ans = 0;
    while (!pq.empty()) {

        auto [a, b] = pq.top(); pq.pop();
        if (dist[b.y] != -1) continue;
        dist[b.y] = -a;
        ans += -a - (-a + b.x) / 10;

        for (auto [u, v] : adj[b.y]) {
            if (dist[u] == -1) {
                pq.push(mp(a - v, mp(-v, u)));
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}