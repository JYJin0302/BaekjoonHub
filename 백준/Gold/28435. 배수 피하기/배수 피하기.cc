#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fastPow(ll b, ll ex, ll mod) {
    ll res = 1;
    while (ex) {
        if (ex & 1) res = res * b % mod;
        b = b * b % mod;
        ex >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    const ll mod = 1e9 + 7;

    vector<ll> cnt(m);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        cnt[x % m]++;
    }

    ll ans = cnt[0] + 1;

    for (int i = 1; i <= m / 2; i++) {
        if (m - i == i) {
            ans = ans * (cnt[i] + 1) % mod;
        }
        else {
            ll tmp = (fastPow(2, cnt[i], mod) + fastPow(2, cnt[m - i], mod) + mod - 1) % mod;
            ans = ans * tmp % mod;
        }
    }
    ans = (ans - (n + 1) + mod) % mod;
    cout << ans ;

}