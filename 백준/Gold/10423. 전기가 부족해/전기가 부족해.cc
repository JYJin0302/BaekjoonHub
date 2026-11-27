#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> root;

ll find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, k;
    cin >> n >> m >> k;

    root = vector<ll>(n + 1);
    for (int i = 0; i <= n; i++) root[i] = i;

    vector<ll> base(k);
    for (auto& i : base) cin >> i;

    for (int i = 1; i < k; i++) {
        root[base[i]] = root[base[0]];
    }

    vector<vector<pair<ll, ll>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
        adj[b].push_back({ a, c });
    }

    priority_queue<tuple<ll, ll, ll>> pq;
    for (ll i : base) {

        for (auto k : adj[i]) {
            int a, b;
            tie(a, b) = k;

            pq.push({ -b, a, i });
        }
    }

    ll ans = 0;
    while (!pq.empty()) {

        ll a, b, c;
        tie(a, b, c) = pq.top();
        pq.pop();

        find(b), find(c);
        if (root[b] == root[c])continue;

        root[root[b]] = root[c];
        ans -= a;

        for (auto k : adj[b]) {

            ll x, y;
            tie(x, y) = k;

            find(b), find(x);
            if (root[b] == root[x]) continue;

            pq.push({ -y, x, b });
        }
    }

    cout << ans;
}