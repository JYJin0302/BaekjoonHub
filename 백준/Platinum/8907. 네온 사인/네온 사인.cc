#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {

    ll n;
    cin >> n;

    ll ans = n * (n - 1) * (n - 2) / 6;
    vector<ll> cnt(n + 1);

    for (int a = 1; a <= n; a++) {
        for (int b = a + 1; b <= n; b++) {
            bool x;
            cin >> x;

            if (x) cnt[a]++, cnt[b]++;
        }
    }

    ll tmp = 0;
    for (int i = 1; i <= n; i++) {
        tmp += cnt[i] * (n - cnt[i] - 1);
    }

    cout << ans - tmp / 2 << '\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}