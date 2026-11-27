#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

vector<pair<ll, ll>> adj[101010];

ll dist[101010], dist2[101010];

void solve() {

    int n, m;
    cin >> n >> m;

    int s, e;
    cin >> s >> e;
    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));
    }

    priority_queue<pair<ll, ll>> pq;
    memset(dist, -1, sizeof(dist));
    pq.push(mp(0, s));
    while (!pq.empty()) {
        ll a, b;
        tie(a, b) = pq.top();
        pq.pop();

        if (dist[b] != -1) continue;
        dist[b] = -a;

        for (auto f : adj[b]) {
            ll x, y;
            tie(x, y) = f;

            if (dist[x] == -1) pq.push(mp(a - y, x));
        }
    }

    swap(dist, dist2);

    memset(dist, -1, sizeof(dist));
    pq.push(mp(0, s));
    while (!pq.empty()) {
        ll a, b;
        tie(a, b) = pq.top();
        pq.pop();

        if (dist[b] != -1 || b == e) continue;
        dist[b] = -a;

        for (auto f : adj[b]) {
            ll x, y;
            tie(x, y) = f;

            if (dist[x] == -1) pq.push(mp(a - y, x));
        }
    }
    swap(dist, dist2);


    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == dist[e] * 2 && dist2[i] != dist[i]) ans.push_back(i);
    }

    if (ans.empty()) cout << "*\n";
    else {
        for (auto f : ans) cout << f << ' ';
        cout << '\n';
    }
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}