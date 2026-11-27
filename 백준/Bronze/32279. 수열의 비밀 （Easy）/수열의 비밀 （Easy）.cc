#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

ll gcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

ll fastPow(ll b, ll ex, ll mod) {
    ll res = 1;
    while (ex) {
        if (ex & 1) res = res * b % mod;
        ex >>= 1;
        b = b * b % mod;
    }
    return res;
}


void solve() {

    int n; cin >> n;

    ll p, q, r, s;
    cin >> p >> q >> r >> s;

    vector<ll> A(n + 1);
    cin >> A[1];
    for (int i = 1; i <= n; i++) {
        if (i * 2 <= n) A[i * 2] = A[i] * p + q;
        if (i * 2 + 1 <= n) A[i * 2 + 1] = A[i] * r + s;
    }

    ll ans = 0;
    for (auto f : A)ans += f;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}