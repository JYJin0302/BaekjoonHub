#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
#define mp make_pair
#define all(x) x.begin(), x.end()

#define x first
#define y second

vector<int> adj[101010];
ll S[101010];
ll T[101010];
ll K[101010];

ll dist[2][101010];

void solve() {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b >> T[i] >> K[i];
        S[i] = a + b;

        adj[a].push_back(i);
        adj[b].push_back(i);
    }

    memset(dist, -1, sizeof(dist));
    priority_queue<pair<ll, pair<ll, ll>>> pq;
    pq.push(mp(1, mp(0, 1)));
    while (!pq.empty()) {
        ll a = pq.top().first;
        auto [d, b] = pq.top().second;
        pq.pop();

        if (dist[a][b] != -1) continue;
        dist[a][b] = -d;

       // cout << "Upd: " << a << ' ' << b << " | " << -d << '\n';

        for (auto f : adj[b]) {
            int nx = S[f] - b;
            if (dist[a][nx] == -1) {
                pq.push(mp(a, mp(d - T[f], nx)));
            }

            if (a == 1) {
                if (dist[0][nx] == -1) {
                    pq.push(mp(0, mp(d - T[f] + K[f], nx)));
                }
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << dist[0][i] << ' ';
    }
    cout << '\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}