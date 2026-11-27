#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 100000000


int main() {

    ll n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({ b, c });
    }

    vector<ll> dist(n + 1, INF);
    dist[1] = 0;

    queue<ll> q;
    q.push(1);
    vector<bool> inQ(n + 1);
    inQ[1] = 1;

    vector<ll> cnt(n + 1);
    cnt[1]++;

    while (!q.empty()) {

        ll a = q.front();
        q.pop();
        inQ[a] = 0;

        for (auto i : adj[a]) {
            ll x, y;
            tie(x, y) = i;

            if (dist[x] > dist[a] + y) {
                dist[x] = dist[a] + y;

                if (!inQ[x]) {
                    cnt[x]++;
                    if (cnt[x] >= n) {
                        cout << -1;
                        return 0;
                    }

                    inQ[x] = 1;
                    q.push(x);
                }
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (dist[i] == INF) dist[i] = -1;
        cout << dist[i] << '\n';
    }
}