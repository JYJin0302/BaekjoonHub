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
    string s;
    cin >> s;

    ll ans = 0;

    int ix = 0;
    while (ix < n) {
        while (ix < n && s[ix] == '0') ix++;

        if (ix == n) break;
        int nx = ix;
        while (nx < n && s[nx] == '1') nx++;

        ll len = nx - ix;
        ans += len * (len + 1) / 2;
        ix = nx;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}