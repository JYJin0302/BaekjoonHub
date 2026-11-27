#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {
    
    int n;
    ll k;
    cin >> n >> k;

    vector<pair<ll, ll>> A(n);
    for (auto& i : A) cin >> i.x >> i.y;

    ll ans = 0, tc = 0;

    ll l = 0, r = 1e9, res = -1;
    while (l <= r) {

        ll md = (l + r) >> 1;

        ll cnt = 0, val = 0;
        for (auto[a,b] : A){
            
            ll tc = (b - md) / a + 1;
            if (tc <= 0 || b < md) continue;

            cnt += tc;
            if (cnt > k) break;
            val += tc * b;
            val -= a * tc * (tc - 1) / 2;
        }

        if (cnt <= k) {
            ans = max(ans, val);
            res = md;
            tc = cnt;
            r = md - 1;
        }
        else l = md + 1;

    }

    if (tc < k && res > 0) ans += (res - 1)* (k - tc);

    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}