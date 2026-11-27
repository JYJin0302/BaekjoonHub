#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<pair<ll, ll>> adj[303030];
bool isOk(ll val, ll cur, int pos) {
    for (int j = 59; j >= pos; j--) {
        if (val & (1ll << j)) {
            if (cur & (1ll << j)) {}
            else return 0;
        }
    }
    return 1;
}

void solve() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));
    }

    ll ans = 0;
    for (int i = 59; i >= 0; i--) {
        vector<bool> vis(n + 1);
        queue<int> q;
        q.push(1);
        vis[1] = 1;
        while (!q.empty()) {
            int a = q.front(); q.pop();
            for (auto [x, y] : adj[a]) {
                if (!vis[x] && isOk(y, ans, i)) {
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }

        if (!vis[n]) ans += 1ll << i;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}