#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

const ll mod = 998244353;

ll fastPow(ll b, ll ex) {
    ll res = 1;
    while (ex) {
        if (ex & 1) {
            res = res * b % mod;
        }
        ex >>= 1;
        b = b * b % mod;
    }
    return res;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    vector<ll> cnt(n + 1);
    ll val = 1;
    for (int i = 1; i < m; i++) {
        val = val * (n - i + 1) % mod;
        val = val * fastPow(i, mod - 2) % mod;
    }
    for (int i = m; i <= n; i++) {

        val = val * (n - i + 1) % mod;
        val = val * fastPow(i, mod - 2) % mod;

        cnt[i] = val * fastPow(25, n - i) % mod;
    }

    ll ans = cnt[m] * cnt[m] % mod;
    for (int i = m + 1; i <= n; i++) {
        ans += 2*cnt[i] * cnt[m] % mod;
        ans %= mod;
    }
    cout << ans;


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(3);
    solve();
    return 0;
}
