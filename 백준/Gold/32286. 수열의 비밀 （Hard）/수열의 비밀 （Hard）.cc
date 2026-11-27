#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


ll p, q, r, s;
int k;
const int mod = 1e9 + 7;


void solve() {

    cin >> k;
    cin >> p >> q >> r >> s;

    ll a1;
    cin >> a1;

    ll ans = a1;
    ll ss = a1;
    ll cnt = 1;
    for (int i = 1; i < k; i++) {

        ss = ss * (p + r) + cnt*( q + s);
        ss %= mod;
        ans += ss;
        ans %= mod;

        cnt = cnt * 2 % mod;
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