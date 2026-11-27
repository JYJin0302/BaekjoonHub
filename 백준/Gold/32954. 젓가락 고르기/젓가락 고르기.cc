#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    ll n, k;
    cin >> n >> k;
    vector<ll> A(n);
    for (auto& i : A) cin >> i;

    ll tot = 0;
    for (auto f : A) tot += f / 2;
    if (k == 0) {
        cout << 0 << '\n';
        return;
    }

    if (tot < k) {
        cout << -1 << '\n';
        return;
    }

    ll ans = n;
    ll v1 = 0;
    for (auto& f : A) {
        f--;
        v1 += f / 2;
    }

    ans += min(v1, k - 1) * 2;
    k -= min(v1, k - 1);
    ans += k;

    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}