#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<tuple<int, int, int>> adj[201];
long double cost[201][2];

void solve() {

    int n, m , st, en, s, p, yy;
    cin >> n >> m >> st >> en >> s >> p >> yy;

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        cost[i][0] = cost[i][1] = -1;
    }

    while (m--) {

        int a, b, c, d;
        cin >> a >> b >> c >> d;


        adj[a].push_back({ b, c, d});
        adj[b].push_back({ a, c, d});
    }

    priority_queue<tuple<long double, int, int>> pq;
    pq.push({ 0.0, st, 0 });
    while (!pq.empty()) {

        long double a;
        int b, c;
        tie(a, b, c) = pq.top();
        pq.pop();

        if (cost[b][c] != -1) continue;
        cost[b][c] = -a;

        for (auto i : adj[b]) {

            int x, y, z;
            tie(x, y, z) = i;

            
            if (cost[x][1] == -1) {
                if (c == 1) pq.push({ a - z*p, x, 1 });
                else pq.push({ a - z*p - s, x, 1 });
            }
            if (cost[x][0] == -1) {
                pq.push({ a - 0.01*y*(yy+z*p), x, 0 });
            }
        }
    }

    cout << abs(min(cost[en][0], cost[en][1])) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(2);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}