#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, m;
int distS[5050], distE[5050];
vector<pair<int, int>> adj[5050];

void setD(int s, int dist[]) {
    for (int i = 1; i <= n; i++) dist[i] = -1;
    priority_queue<pair<int, int>> pq;
    pq.push(mp(0, s));
    while (!pq.empty()) {
        auto [a, b] = pq.top(); pq.pop();
        if (dist[b] != -1) continue;
        dist[b] = -a;

        for (auto f : adj[b]) {
            if (dist[f.x] == -1) {
                pq.push(mp(a - f.y, f.x));
            }
        }
    }
}

void solve() {

    cin >> n >> m;

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));
    }

    setD(1, distS);
    setD(n, distE);

    ll res = 1e18;
    for (int i = 1; i <= n; i++) {
        for (auto [a, b] : adj[i]) {
            ll tval = (ll)distS[i] + distE[a] + b;
            if (tval > distS[n]) res = min(res, tval);
        }
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}