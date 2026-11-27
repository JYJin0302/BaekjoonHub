#include <bits/stdc++.h>
#include <random>
#include <chrono>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const ll INF = 1e9 + 20;
void solve() {

    int n, a, b;
    cin >> n >> a >> b;

    vector<pair<pair<int, int>, int>> edg;
    while (a--) {
        int u, v, d;
        cin >> u >> v >> d;
        edg.push_back(mp(mp(u, v), d));
    }

    while (b--) {
        int u, v, d;
        cin >> u >> v >> d;
        edg.push_back(mp(mp(v, u), -d));
    }
    for (int i = 1; i < n; i++) {
        edg.push_back(mp(mp(i + 1, i), 0));
    }

    vector<ll> dist(n + 1, INF);
    dist[1] = 0;
    for (int i = 0; i < n; i++) {

        for (auto& f : edg) {
            auto [u, v] = f.x;
            ll d = f.y;

            if (dist[u] + d < dist[v]) {
                if (i == n - 1) {
                    cout << -1;
                    return;
                }
                dist[v] = dist[u] + d;
            }
        }
    }

    if (dist[n] == INF) cout << -2;
    else cout << dist[n];

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}