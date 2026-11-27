#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> adj[10101], rev[10101];
int topo[10101];
const int mod = 1e9;

void solve() {

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edg;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        rev[b].push_back(a);
        edg.push_back(mp(a, b));
    }

    vector<bool> vis(n+1), vis2(n+1);
    vis[1] = 1;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int a = q.front(); q.pop();

        for (auto f : adj[a]) {
            if (!vis[f]) {
                vis[f] = 1;
                q.push(f);
            }
        }
    }
    vis2[2] = 1;
    q.push(2);
    while (!q.empty()) {
        int a = q.front(); q.pop();

        for (auto f : rev[a]) {
            if (!vis2[f]) {
                vis2[f] = 1;
                q.push(f);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        rev[i].clear();
    }

    for (auto [a, b] : edg) {
        if (vis[a] && vis2[b]) {
            adj[a].push_back(b);
            topo[b]++;
        }
    }

    vector<ll> ans(n + 1);
    ans[1] = 1;

    bool chk = 0;
    q.push(1);
    while (!q.empty()) {
        int a = q.front(); q.pop();
        for (auto f : adj[a]) {

            ans[f] += ans[a];
            if (ans[f] >= mod) {
                chk = 1;
                ans[f] %= mod;
            }
            topo[f]--;
            if (topo[f] == 0) q.push(f);
        }
    }

    for (int i = 1; i <= n; i++) if (topo[i]) {
        cout << "inf\n";
        return;
    }

    string s = to_string(ans[2]);
    if (chk) {
        while (s.size() < 9) s = '0' + s;
    }
    cout << s << '\n';
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}