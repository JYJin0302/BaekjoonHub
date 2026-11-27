#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> adj[101], rev[101];

void solve() {

    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        rev[b].push_back(a);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        queue<int> q;
        vector<bool> vis(n + 1);
        q.push(i);
        int cnt = 0;
        while (!q.empty()) {
            int a = q.front(); q.pop();
            vis[a] = 1;
            for (auto f : adj[a]) if (!vis[f]) {
                vis[f] = 1;
                q.push(f);
                cnt++;
            }                
        }

        q.push(i);
        while (!q.empty()) {
            int a = q.front(); q.pop();
            vis[a] = 1;
            for (auto f : rev[a]) if (!vis[f]) {
                vis[f] = 1;
                q.push(f);
                cnt++;
            }
        }

        if (cnt == n - 1) ans++;
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