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

    int n;
    cin >> n;
    ll a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        
        int l = to_string(x).size();
        while (l--) a *= 10;
        a += x;
    }
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;

        int l = to_string(x).size();
        while (l--) b *= 10;
        b += x;
    }

    if (a > b) cout << b;
    else cout << a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}