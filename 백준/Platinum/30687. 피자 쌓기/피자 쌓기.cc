#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

const ll mod = 1e9 + 7;
ll fastPow(ll b, ll ex) {
    ll res = 1;
    while (ex) {
        if (ex & 1) res = res * b % mod;
        b = b * b % mod;
        ex >>= 1;
    }
    return res;
}

ll f[503030];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> A(n + 1);
    for (int i = 1; i <= n; i++) cin >> A[i];

    f[0] = 1;
    for (int i = 1; i <= 500000; i++) f[i] = f[i - 1] * i % mod;

    ll ans = 0;
    ll tot = 0;
    for (int i = 1; i <= n; i++) {
        tot += A[i];
    }
    tot = f[tot];
    for (int i = 1; i <= n; i++) {
        tot *= fastPow(f[A[i]], mod - 2);
        tot %= mod;
    }

    ll tcnt = 0;
    for (int i = n; i >= 1; i--) {
        tcnt += A[i];
        ll ansAdd = tot * fastPow(tcnt, mod - 2) % mod * A[i] % mod;
        ansAdd %= mod;
        ans += ansAdd;
        ans %= mod;
    }
    cout << ans;

}
