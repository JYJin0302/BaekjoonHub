#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {

    vector<ll> val(64);
    val[0] = 1;
    for (int i = 1; i < 64; i++) val[i] = val[i - 1] * 2;

    vector<int> cnt(66);

    int q;
    cin >> q;
    while (q--) {

        ll x;
        cin >> x;

        // cout << c << ' ' << x << '\n';

        if (x > 0) {
            ll tx = log2(x);
            cnt[tx]++;
        }
        else if (x < 0) {
            x *= -1;
            ll tx = log2(x);
            cnt[tx]--;
        }

        ll ans = 0;
        ll tmp = 0;
        for (ll i = 0; i < 64; i++) {
            tmp += cnt[i];
            if (tmp) ans = val[i];

            tmp /= 2;
        }
        cout << ans << '\n';
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

}