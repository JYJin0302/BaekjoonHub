#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int INF = 10101010;
bool conn[202][202];
int dist[202][202];
int dp[202][202];
void solve() {

    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<int> cost(n + 1);
    for (int i = 1; i <= n; i++) cin >> cost[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = dp[i][j] = INF;
            conn[i][j] = 0;
        }
        dist[i][i] = cost[i];
    }
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        conn[a][b] = 1;
        dist[a][b] = cost[a] + cost[b];
    }

    for (register int k = 1; k <= n; k++) {
        for (register int i = 1; i <= n; i++) {
            for (register int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j] - cost[k]);
            }
        }
    }

    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }*/

    if (dist[s][t] == INF || dist[t][s] == INF) {
        cout << -1 << '\n';
        return;
    }

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push(mp(-cost[t], mp(t, t)));

    while (!pq.empty()) {
        int v = pq.top().x;
        auto [a, b] = pq.top().y;
        pq.pop();
        if (dp[a][b] != INF) continue;
        dp[a][b] = -v;

        if (a == s && b == s) {
            cout << -v << '\n';
            return;
        }
        //cout << -v << " | " << a << ' ' << b << '\n';

        for (register int j = 1; j <= n; j++) {
            if (conn[j][a] && dist[j][a] != INF && dp[j][b] == INF) {
                int nval = v - dist[j][a] + cost[a];
                if (j == b) nval += cost[b];
                pq.push(mp(nval, mp(j, b)));
            }

            if (conn[b][j] && dist[b][j] != INF && dp[a][j] == INF) {
                int nval = v - dist[b][j] + cost[b];
                if (j == a) nval += cost[a];
                pq.push(mp(nval, mp(a, j)));
            }
        }

        if (dist[b][a] != INF && dp[b][a] == INF) {
            int nval = v - dist[b][a] + cost[a] + cost[b];
            pq.push(mp(nval, mp(b, a)));
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}