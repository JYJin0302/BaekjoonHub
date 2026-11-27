#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

const ll mod = 998244353;

void solve() {

    ll w, h, k, t;
    cin >> w >> h >> k >> t;

    ll ans = 1;
    for (int i = 0; i < k; i++) {

        ll x, y;
        cin >> x >> y;

        ll xl = max(1ll, x - t);
        ll xr = min(w, x + t);

        ll yl = max(1ll, y - t);
        ll yr = min(h, y + t);

        ll val = (xr - xl + 1) * (yr - yl + 1) % mod;
        ans = ans * val % mod;

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