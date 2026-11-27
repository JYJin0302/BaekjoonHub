#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {

    ll n, k;
    cin >> n >> k;

    ll l = 1, r = n * n, ans = -1;
    while (l <= r) {
        ll md = (l + r) >> 1;
        ll cnt = 0;
        for (int i = 1; i <= n; i++) cnt += min(n, md / i);

        if (cnt >= k) {
            ans = md;
            r = md - 1;
        }
        else l = md + 1;
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