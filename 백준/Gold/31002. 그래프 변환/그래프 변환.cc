#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

const int mod = 1e9 + 7;
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

    int n, k;
    cin >> n >> k;

    ll inv2 = fastPow(2, mod - 2, mod);

    ll a = n, b = n - 1;
    while (k--) {
        ll na = a * b % mod * inv2 % mod;
        ll nb = (2 * b - 2) % mod;
        a = na;
        b = nb;
    }

    cout << a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}