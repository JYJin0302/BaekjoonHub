#include <bits/stdc++.h>
#include <random>
#include <chrono>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const ll INF = 1e13;

int I[10101], O[10101];

vector<int> adj[10101];
bool vis[10101];
void solve() {

    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        I[a]++;
        O[b]++;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;

        bool ok = 1;
        vis[i] = 1;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int a = q.front(); q.pop();
            if (!I[a] || !O[a]) ok = 0;
            for (auto f : adj[a]) if (!vis[f]) {
                vis[f] = 1;
                q.push(f);
            }
        }

        ans += ok;
    }
    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}