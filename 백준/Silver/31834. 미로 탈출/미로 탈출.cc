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

    ll n, a, b;
    cin >> n >> a >> b;

    // no 중복
    if (min(a, b) == 1 && max(a, b) == n) {
        cout << 0 << '\n';
        return;
    }
    if (abs(a - b) == 1 || a == 1 || a == n) {
        cout << 1 << '\n';
        return;
    }
    cout << 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}