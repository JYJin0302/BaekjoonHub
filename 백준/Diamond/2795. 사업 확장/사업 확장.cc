#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int INF = 101010;
bool conn[101][101];
int dist[101][101];
int dp[101][101];
void solve() {

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = dp[i][j] = INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        conn[a][b] = 1;
        dist[a][b] = 1;
    }
    for (int i = 1; i <= n; i++) dist[i][i] = 0;

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    //for (int i = 1; i <= n; i++) {
    //    for (int j = 1; j <= n; j++) {
    //        cout << dist[i][j] << ' ';
    //    }
    //    cout << '\n';
    //}

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push(mp(-1, mp(2, 2)));

    while (!pq.empty()) {
        int v = pq.top().x;
        auto [a, b] = pq.top().y;
        pq.pop();
        if (dp[a][b] != INF) continue;
        dp[a][b] = -v;
        //cout << -v << " | " << a << ' ' << b << '\n';
        if (a == 1 && b == 1){
            cout << -v << '\n';
            return;
        }
        for (int j = 1; j <= n; j++) {
            if (dist[j][a] != INF && dp[j][b] == INF) {
                int nval = v - dist[j][a];
                if (j == b) nval++;
                pq.push(mp(nval, mp(j, b)));
            }

            if (dist[b][j] != INF && dp[a][j] == INF) {
                int nval = v - dist[b][j];
                if (j == a) nval++;
                pq.push(mp(nval, mp(a, j)));
            }
        }

        if (dist[b][a] != INF && dp[b][a] == INF) {
            int nval = v - dist[b][a] + 1;
            pq.push(mp(nval, mp(b, a)));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
   // cin >> t;
    while (t--) solve();
}