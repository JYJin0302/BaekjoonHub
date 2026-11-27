#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


vector<pair<int, pair<ll, ll>>> adj[202020];
const int mod = 1e9 + 7;

void solve() {

    int n, m;
    cin >> n >> m;

    vector<ll> D(n + 1);
    for (int i = 2; i <= n; i++) cin >> D[i];

    ll mult = 1;
    while (m--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        
        if (D[a] == D[b]) {
            mult = mult * (d - c + 1) % mod;
        }
        else if (D[a] < D[b]) {
            adj[b].push_back(mp(a, mp(c, d)));
        }
        else {
            adj[a].push_back(mp(b, mp(c, d)));
        }
    }

    ll ans = 1;

    for (int i = 2; i <= n; i++) {
        ll v1 = 1, v2 = 1;
        bool ok = 1;
        for (auto f : adj[i]) {
            auto [l, r] = f.y;
            if (D[f.x] + r < D[i]) {
                ok = 0;
                break;
            }
            l = max(l, D[i] - D[f.x]);
            v1 = v1 * (r - l + 1) % mod;
            v2 = v2 * (r - l + 1 - (l+ D[f.x] == D[i])) % mod;
        }

        if (!ok) {
            cout << 0 << '\n';
            return;
        }

        ll mul = (v1 - v2 + mod) % mod;
        ans = ans * mul % mod;
    }

    cout << ans * mult % mod << '\n';

}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}