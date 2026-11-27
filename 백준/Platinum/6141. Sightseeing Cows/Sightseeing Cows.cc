#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, m;
int A[1010];
vector<pair<int, int>> adj[1010];

bool chk(ld d) {

    vector<ld> dist(n + 1, 1e8);
    dist[1] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j <= n; j++) {
            for (auto& [u, v] : adj[j]) {
                dist[u] = min(dist[u], dist[j] + v * d - A[u]);
            }
        }
    }

    for (int j = 1; j <= n; j++) {
        for (auto& [u, v] : adj[j]) {
            if (dist[u] > dist[j] + v * d - A[u]) {
                return 1;
            }
        }
    }
    return 0;

}

void solve() {

    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> A[i];

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back(mp(b, c));
    }

    ld l = 0, r = 10000, ans = -1;
    while (r - l > 1e-6) {
        ld md = (l + r) / 2;

        bool res = chk(md);
       // cout << "res: " << md << " | " << res << '\n';

        if (res) {
            ans = l = md;
        }
        else r = md;
    }
        
    if (ans < -0.5) {
        cout << 0;
        return;
    }

    cout << fixed << setprecision(2);
    //cout << l << ' ' << r << '\n';
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}